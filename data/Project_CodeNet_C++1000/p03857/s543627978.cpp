#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
const int INF = INT_MAX;
const ll MOD = 998244353;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

int main() {
    // insert code here...    return 0;
    //////
    // input from txt
    /*
     std::ifstream in("input.txt");
     std::cin.rdbuf(in.rdbuf());
     std::ofstream out("output.txt");
     std::cout.rdbuf(out.rdbuf());
     ////
     */
    int N,K,L;
    cin >> N >> K >> L;
    UnionFind road(N),train(N);
    repeat(i, K){
        int p,q;
        cin >> p >> q;
        p--;q--;
        road.unionSet(p, q);
    }
    repeat(i, L){
        int r,s;
        cin >> r >> s;
        r--;s--;
        train.unionSet(r, s);
    }
    map<Pii,int> S;
    repeat(i, N){
        S[make_pair(road.root(i),train.root(i))]++;
    }
    repeat(i, N){
        cout << S[make_pair(road.root(i),train.root(i))];
        if(i==N-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
    return 0;
}


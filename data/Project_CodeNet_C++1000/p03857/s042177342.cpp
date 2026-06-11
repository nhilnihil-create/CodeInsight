#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

struct UnionFind{
    vector<int> par;
    vector<int> rank;
    UnionFind(int n){
        par = vector<int>(n, -1);
        rank = vector<int>(n, 0);
    }

    int root(int x){
        if(par[x] < 0){
            return x;
        }
        return par[x] = root(par[x]);
    }

    bool isSame(int a, int b){
        return root(a) == root(b);
    }

    bool merge(int a, int b){
        a = root(a);
        b = root(b);
        if(isSame(a, b)){
            return false;
        }
        if(rank[a] < rank[b]){
            swap(a, b);
        }
        if(rank[a] == rank[b]){
            rank[a] ++;
        }
        par[a] += par[b];
        par[b] = a;
        return true;
    }

};

int main(){
    int N, K, L;
    cin >> N >> K >> L;
    vector<pair<int, int>> cs;
    UnionFind pq(N);
    UnionFind rs(N);
    rep(i, K){
        int p, q;
        cin >> p >> q;
        p --;
        q --;
        pq.merge(p, q);
    }
    rep(i, L){
        int r, s;
        cin >> r >> s;
        r --;
        s --;
        rs.merge(r, s);
    }
    rep(i, N){
        pair<int, int> c = {pq.root(i), rs.root(i)};
        cs.push_back(c);
    }
    sort(cs.begin(), cs.end());
    rep(i, N){
        pair<int, int> c = {pq.root(i), rs.root(i)};
        int cnt = upper_bound(cs.begin(), cs.end(), c) - lower_bound(cs.begin(), cs.end(), c);
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}

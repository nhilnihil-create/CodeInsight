#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

vector<int> E[110000];

int maxD[110000] = {}, vCol[110000] = {};

void func(int pos, int d, int col){
    if(maxD[pos] >= d){
        return;
    }
    if(maxD[pos] == 0){
        vCol[pos] = col;
    }
    maxD[pos] = d;
    for(int to : E[pos]){
        func(to, d - 1, col);
    }
}

int main(){
    int N, M, Q;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    cin >> Q;
    vector<T> v;
    for(int i = 0; i < Q; i++){
        int x, d, c;
        cin >> x >> d >> c;
        v.push_back(T(x, d + 1, c));
    }
    reverse(v.begin(), v.end());
    for(T t : v){
        func(get<0>(t), get<1>(t), get<2>(t));
    }
    for(int i = 1; i <= N; i++){
        cout << vCol[i] << endl;
    }
    return 0;
}
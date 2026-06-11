#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<vector<int>> G;

int subtree(int v){
    vector<int> a;
    for(auto nv : G[v]){
        a.push_back(subtree(nv));
    }
    int res = 0;
    sort(a.rbegin(), a.rend());
    rep(i,a.size()){
        chmax(res, a[i] + i + 1);
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    G.resize(n);
    rep(i,n-1){
        int a;
        cin >> a;
        --a;
        G[a].push_back(i+1);
    }
    cout << subtree(0) << endl;
    return 0;
}

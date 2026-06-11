#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> path;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(i == 0){
            path.push_back(a);
            path.push_back(b);
        }
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> used(n, false);
    for(auto x : path) used[x] = true;
    rep(i,2){
        while(true){
            bool flag = true;
            for(auto nv : G[path.back()]){
                if(!used[nv]){
                    used[nv] = true;
                    path.push_back(nv);
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        reverse(path.begin(), path.end());
    }
    cout << path.size() << endl;
    for(auto p : path){
        cout << p+1 << " ";
    }
    cout << endl;
	return 0;
}
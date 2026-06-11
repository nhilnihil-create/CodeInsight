#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    int n,m; cin >> n >> m;
    vector<vector<int> > v(n,vector<int>());
    for (int i = 0; i < m; i++) {
      int a,b; cin >> a >> b;
      a--;
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    string ans = "IMPOSSIBLE";
    for(int i = 0;i < v[0].size();i++){
        int z = v[0][i];
        for(int j = 0;j < v[z].size();j++){
            if(n-1 == v[z][j]){
                ans = "POSSIBLE";
                break;
            }
        }
    }
    cout << ans;
}


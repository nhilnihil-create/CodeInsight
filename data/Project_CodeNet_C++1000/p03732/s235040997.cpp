#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 20;
vector<int> g[N];
vector<int> vis(N);
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        int n, w;
        cin >> n >> w;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].ff >> v[i].ss;
        }
        vector<int> ans[4];
        for(int i = 0; i < n; i++){
            ans[v[i].ff - v[0].ff].pb(v[i].ss);
        }
        for(int i = 0; i < 4; i++){
            sort(all(ans[i]), greater<int> ());
            // for(auto &it : ans[i]){
            //     cout << it << ' ';
            // }
            // cout << '\n';
        }
        vector<vector<int>> pre(n + 1, vector<int> (4));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < ans[i].size(); j++){
                pre[j + 1][i] = pre[j][i] + ans[i][j];
            }
            // for(int j = 0; j < ans[i].size(); j++){
            //     cout << pre[j + 1][i] << ' '; 
            // } 
            // cout << '\n';
        }
        int res = 0;
        for(int i = 0; i < ans[0].size() + 1; i++){
            for(int j = 0; j < ans[1].size() + 1; j++){
                for(int k = 0; k < ans[2].size() + 1; k++){
                    for(int l = 0; l < ans[3].size() + 1; l++){
                        int sum = pre[i][0] + pre[j][1] + pre[k][2] + pre[l][3];
                        if((i + j + k + l) * v[0].ff + (j + 2 * k + 3 * l) <= w){
                            res = max(res, sum);
                        }
                    }
                }
            }
        }
        cout << res << '\n';
    }
}
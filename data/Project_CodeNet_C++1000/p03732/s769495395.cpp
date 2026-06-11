#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    ll N,W; cin >> N >> W;
 
    ll w[105],v[105];
 
    vector<ll> lis[4];
 
    cin >> w[0] >> v[0];
    lis[0].push_back(v[0]);
 
    for (int i =1;i < N;i++){
        cin >> w[i] >> v[i];
        lis[w[i]-w[0]].push_back(v[i]);
    }
 
    vector<ll> sum[4];
 
    for (int i = 0;i < 4;i++){
        sort(lis[i].begin(),lis[i].end());
        reverse(lis[i].begin(),lis[i].end());
        sum[i].push_back(0);
        for (int j = 0;j < lis[i].size();j++){
            sum[i].push_back(sum[i][j]+lis[i][j]);
        }
    }
 
    ll ans = -1;
 
    for (int i = 0;i <= lis[0].size();i++){
        for (int j = 0;j <= lis[1].size();j++){
            for (int k = 0;k <= lis[2].size();k++){
                for (int l = 0;l <= lis[3].size();l++){
                    if(w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l > W) continue;  
                    ans = max(sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l], ans);
                }
            }
        }
    }
 
    cout << ans << endl;
 
    return 0;
 
}
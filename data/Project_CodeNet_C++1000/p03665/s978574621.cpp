#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,p;cin >> n >> p;
    vector<vector<ll>> dp(n+1,vector<ll>(2));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        for(int j=0;j<2;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][(j+a)%2]+=dp[i][j];
        }
    }
    cout << dp[n][p] << endl;
}
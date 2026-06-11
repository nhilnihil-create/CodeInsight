#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
  
/*------------------------------------------------------------------*/
int main(){
    int n, p; cin >> n >> p;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll dp[60][2]; // １：奇数　０：偶数
    
    rep(i, n){
        if(i == 0){
            if(a[i] % 2 == 0){
                dp[i][0] = 2;
                dp[i][1] = 0;
            }else{
                dp[i][0] = 1;
                dp[i][1] = 1;
            }
            continue;
        }
        if(a[i] % 2 == 0){
            dp[i][0] = dp[i - 1][0] * 2;
            dp[i][1] = dp[i - 1][1] * 2;
        }else{
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
    }
    if(p % 2 == 0)cout << dp[n - 1][0] << endl;
    else cout << dp[n - 1][1] << endl;
}
#include <bits/stdc++.h>
#define MAXN 100010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const int mod = 1e9 + 7;


int main (){
    ll n, a, dp[55][5000], tmp;
    memset(dp, 0, sizeof dp);

    cin >> n >> a;

    dp[0][0] = 1;

    for (int i=1; i<=n; i++){
        cin >> tmp;
        for (int j=i; j>=1; j--){
            for (int k=0; k<=2500; k++){
                dp[j][k + tmp] += dp[j-1][k];
            }
        }
    }

    ll ans = 0;

    for (int i=1; i<=n; i++) ans+= dp[i][i*a];

    cout << ans << endl;
    
    return 0;
}
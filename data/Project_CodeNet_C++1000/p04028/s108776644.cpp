#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back
const int mod = 1e9+7;

char s[5005];
int dp[5005][5005];
int main(){
    int n;
    scanf("%d%s", &n, s);
    int m = strlen(s);
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(j == 0) dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod;
            else dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j])%mod;

            dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]*2%mod)%mod;
        }
    }
    int ans = dp[n][m];
    for(int i=0;i<m;i++) ans = ans*1ll*((mod+1)/2)%mod;
    printf("%d\n", ans);
}
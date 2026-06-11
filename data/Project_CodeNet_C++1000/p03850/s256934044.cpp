#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> piipi;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int a[100005];
ll dp[100005][4];
int main(){
    int n;
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++) dp[i][j] = -1e18;
    }

    scanf("%d", &a[1]);
    dp[1][0] = a[1];
    for(int i=2;i<=n;i++){
        char s[2];
        scanf("%s", s);
        scanf("%d", &a[i]);
        for(int j=0;j<3;j++){
            int op = j%2;
            if(s[0] == '-') op = (op+1)%2;

            // open
            if(s[0] == '-'){
                if(op == 0) dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + a[i]);
                else dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] - a[i]);
            }

            // close
            if(j > 0){
                if(op == 0) dp[i][j-1] = max(dp[i][j-1], dp[i-1][j] + a[i]);
                else dp[i][j-1] = max(dp[i][j-1], dp[i-1][j] - a[i]);
            }

            // none
            if(op == 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i]);
            else dp[i][j] = max(dp[i][j], dp[i-1][j] - a[i]);
        }
    }   
    ll ans = -1e18;
    for(int j=0;j<3;j++) ans = max(ans, dp[n][j]);
    printf("%lld\n", ans);
}
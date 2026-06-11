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
int x[55];
ll dp[55][2505];
int main(){
    int n, a;
    scanf("%d%d", &n, &a);
    for(int i=1;i<=n;i++) scanf("%d", &x[i]);
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=n-1;j>=0;j--){
            for(int k=j*50;k>=0;k--){
                dp[j+1][k+x[i]] = (dp[j+1][k+x[i]] + dp[j][k]);
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans += dp[i][a*i];
    }
    printf("%lld\n", ans);
}
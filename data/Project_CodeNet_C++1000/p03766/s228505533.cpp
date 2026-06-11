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

ll dp[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0, tmp = 1, ans = 1;
    for(int i=1;i<=n;i++){
        if(i >= 4){
            sum = (sum + dp[i-3])%mod;
            tmp = (tmp + sum)%mod;
        }
        dp[i] = tmp;
        if(i < n) ans = (ans + dp[i]*1ll*(n-1)%mod*(n-1))%mod;
        ans = (ans + dp[i]*1ll*(n-1))%mod;
    }
    printf("%lld\n", ans);
}
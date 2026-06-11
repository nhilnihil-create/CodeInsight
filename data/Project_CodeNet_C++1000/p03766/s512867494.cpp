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
    ll sum = 0;
    int cnt = n-2+1;
    for(int i=1;i<=n;i++){
        if(i == 1) dp[i] = n;
        else if(i == 2) dp[i] = n*1ll*n%mod;
        else{
            if(i >= 4) sum = (sum + dp[i-3])%mod;
            dp[i] = (dp[i] + dp[i-1])%mod;

            dp[i] = (dp[i] + (n-1)*1ll*(n-1))%mod;

            dp[i] = (dp[i] + sum)%mod;
            dp[i] = (dp[i] + cnt)%mod;
            cnt--;
        }
    }
    printf("%lld\n", dp[n]);
}
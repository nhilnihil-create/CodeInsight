#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int n;

ll dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;


    dp[n]=n;
    dp[n-1]=1ll*n*n%mod;


    ll s=0;
    for (int i=n-2; i>0; i--) {
	s += dp[i+3]; s%=mod;
	dp[i]=dp[i+1];//1,rest
	dp[i]%=mod;
	dp[i]+=1ll*(n-1)*(n-1)%mod;//c,d,d.... where c>1 and d>1
	dp[i]%=mod;

	ll j=n-(n-i-1);//i+j+1>n
	dp[i]+=(s+j);//c,1,1..1,dp[i+j+1], or we overshoot in j cases
	dp[i]%=mod;
    }
  

    ll ans = dp[1];
    ans %= mod;
    ans += mod;
    ans %= mod;

    out(ans);
  

    return 0;
}

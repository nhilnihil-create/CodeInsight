#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 5e3+1;
const int mod = 1e9+7;
ll dp1[upperlimit][upperlimit];
int main() {
	dp1[0][0]=1;
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(j!=n) dp1[i][j]=dp1[i-1][j+1];
			if(j) dp1[i][j]+=dp1[i-1][j-1]*2ll;
			else dp1[i][j]+=dp1[i-1][j];
			dp1[i][j]%=mod;
		}
	}
	ll ans = dp1[n][int(s.size())];
	ans*=powmod(2,mod-1-int(s.size()),mod);ans%=mod;
	cout << ans;
	return 0;
}
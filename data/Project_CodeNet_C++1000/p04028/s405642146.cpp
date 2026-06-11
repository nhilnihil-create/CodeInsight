#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;
const int MOD=1e9+7;

int n, k;
string s;
int cache[N][N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

int dp(int idx, int rem)
{
	if(idx<0)
		idx=0;
	if(rem==0)
		return (idx==n);
	int &ans=cache[idx][rem];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, rem-1)*2;
	ans+=dp(idx-1, rem-1);
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>k>>s;
	n=s.size();
	int ans=dp(0, k);
	ans*=pow(modinv(2), n, MOD);
	ans%=MOD;
	cout<<ans;
	return 0;
}

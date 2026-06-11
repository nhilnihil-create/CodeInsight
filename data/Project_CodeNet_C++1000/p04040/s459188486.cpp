#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e6+5;
const int MOD=1e9+7;
 
int fact[N], invfact[N];
 
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
 
void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}
 
int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}
 
int get(int x1, int y1, int x2, int y2)
{
	int xdiff=x2-x1;
	int ydiff=y2-y1;
	return nCr(xdiff+ydiff, xdiff);
}
 
int32_t main()
{
	IOS;
	precompute();
	int n, m, p, q;
	cin>>n>>m>>p>>q;
	int ans=nCr(n-1+m-1, n-1);
	int curx=n-p+1, cury=q;
	while(curx<=n && cury>=1)
	{
		ans-=(get(1, 1, curx, cury) * get(curx, cury, n, m))%MOD;
		curx++;
		cury--;
		ans+=MOD;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
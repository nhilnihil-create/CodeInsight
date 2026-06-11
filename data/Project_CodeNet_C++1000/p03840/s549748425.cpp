#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int case1(int a, int b, int c, int d, int e, int f, int g)
{
	int ans=0;
	if(d>=1 && e>=1 && a%2)
	{
		ans+=6;
		a--;
		d--;
		e--;
	}
	ans+=b*2;
	ans+=(d/2)*4;
	ans+=(e/2)*4;
	d%=2;
	e%=2;
	ans+=(a/2)*4;
	ans/=2;
	return ans;
}

int case2(int a, int b, int c, int d, int e, int f, int g)
{
	int mn=min({a, d, e});
	int ans=0;
	ans+=6*mn;
	a-=mn;
	d-=mn;
	e-=mn;
	ans+=b*2;
	ans+=(d/2)*4;
	ans+=(e/2)*4;
	d%=2;
	e%=2;
	ans+=(a/2)*4;
	ans/=2;
	return ans;
}

int case3(int a, int b, int c, int d, int e, int f, int g)
{
	int ans=0;
	ans+=b*2;
	ans+=(d/2)*4;
	ans+=(e/2)*4;
	d%=2;
	e%=2;
	if(d==1 && e==1 && a>=1)
	{
		ans+=6;
		a--;
	}
	ans+=(a/2)*4;
	ans/=2;
	return ans;
}

int32_t main()
{
	IOS;
	int a, b, c, d, e, f, g;
	cin>>a>>b>>c>>d>>e>>f>>g;
	int ans=case1(a, b, c, d, e, f, g);
	int ans2=case2(a, b, c, d, e, f, g);
	int ans3=case3(a, b, c, d, e, f, g);
	cout<<max({ans, ans2, ans3});
	return 0;
}

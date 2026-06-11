#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll a[7];
	for(int i = 0;i<7;++i)
	cin >> a[i];
	ll ans = 0;
	ans += a[0]/2*2;
	ans += a[1];
	ans += a[3]/2*2;
	ans += a[4]/2*2;
	if(a[0]%2==1&&a[3]%2==1&&a[4]%2==1)
	{
		ans+=3;
	}
	ll b[7],c[7];
	for(int i = 0;i<7;i++)
	{
		b[i] = c[i] = a[i];
	}
	ll hoge = 0;
	ll foo = min(a[0],min(a[3],a[4]));
	hoge += 3*foo;
	a[0]-=foo;
	a[3]-=foo;
	a[4]-=foo;
	hoge += a[0]/2*2;
	hoge += a[3]/2*2;
	hoge += a[4]/2*2;
	hoge += a[1];

	ll ans2 = 0;
	if(b[0]>0&&b[3]>0&&b[4]>0)
	{
		ans2 += 3;
		b[0]--;
		b[3]--;
		b[4]--;
		ans2 +=b[0]/2*2;
		ans2 += b[3]/2*2;
		ans2 += b[4]/2*2;
		ans2 += b[1];
	}
	cout<<max(ans,max(ans2,hoge))<<endl;
	return 0;
}
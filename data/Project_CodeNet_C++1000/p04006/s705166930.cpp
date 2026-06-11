#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[2100],b[2100][2100] = {};

int main()
{
	ll n,x,min1 = 9e18,num,ans = 0;
	cin>>n>>x;
	for (int i = 1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if (min1 > a[i])	min1 = a[i],num = i;
		b[0][i] = a[i];
		ans += a[i];
	}
	//cout<<min1<<' '<<num<<'\n';
	for (int t = 1;t<=n-1;t++)
	{
		int i = num,border = num - 1;
		b[t][i] = b[t-1][i];
		ll temp = b[t-1][i];
		if (border == 0) border = n;
		while (i != border)
		{
			i++;
			if (i == n + 1) i = 1;
			if (i - 1 <= 0) b[t][i] = min(b[t - 1][n],b[t-1][i]);
			else b[t][i] = min(b[t-1][i-1],b[t-1][i]);
			temp += b[t][i];
		}
		if (ans > x * t + temp)
		{
			ans = min(ans,x * t +temp);
			/*cout<<t<<'\n';
			for (int i = 1;i<=n;i++) cout<<b[t][i]<<' ';
			cout<<ans<<endl;*/
		}
	}
	cout<<ans;
	
	return 0;
}
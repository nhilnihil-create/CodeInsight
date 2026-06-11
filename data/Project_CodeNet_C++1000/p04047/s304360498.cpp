#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,ans=0;
int a[1005];

int cmp(int a,int b)
{
	return a<b;
}

signed main()
{
	cin>>n;
	for (int i=1;i<=2*n;i++)  cin>>a[i];
	sort(a+1,a+2*n+1,cmp);
	for (int i=0;i<=n-1;i++)  ans+=1ll*a[2*i+1];
	cout<<ans<<endl;
	return 0;
}
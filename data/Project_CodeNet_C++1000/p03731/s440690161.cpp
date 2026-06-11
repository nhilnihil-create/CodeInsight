#include<cstdio>
#include<iostream>
using namespace std;
const int N = 2e5+10;
int n,t,a[N];
int main()
{
	cin>>n>>t;
	for (int i = 0 ; i < n ; i++)
		scanf("%d",&a[i]);

	long long ans = 0;

	for (int i = 1; i < n ;i++)
	{
		ans += min(t, a[i] - a[i-1]);
	}
	ans+=t;
	cout<<ans<<endl;

return 0;
}
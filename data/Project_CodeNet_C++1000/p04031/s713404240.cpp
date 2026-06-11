#include <bits/stdc++.h>
using namespace std;
int n,a[105];
int is_ok(int x)
{
	int s=0;
	for(int i=1; i<=n; i++)
		s+=((a[i]-x)*(a[i]-x));
	return s;
 } 
int main()
{
	int i,v=2e9,ans=0;
	cin>>n;
	for(i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1); 
	for(i=a[1]; i<=a[n];i++)
		if(is_ok(i)<v)
		{
			v=is_ok(i);
			ans=v;
		}
		
	cout<<ans;
	return 0;
}
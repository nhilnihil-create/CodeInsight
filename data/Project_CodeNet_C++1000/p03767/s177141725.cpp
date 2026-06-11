#include<bits/stdc++.h>
using namespace std;
long long n,a[300001],p,ans;
int main()
{
	cin>>n;
	p=n*3;
	for(int i=1;i<=p;i++) cin>>a[i];
	sort(a+1,a+p+1);
	for(int i=p-1;i>=n+1;i-=2) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}

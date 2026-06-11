#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) ans+=(a[i]==a[i-1]);
	if(ans%2==1) ans++;
	cout<<n-ans<<"\n";
	return 0;
}
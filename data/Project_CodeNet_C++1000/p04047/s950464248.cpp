#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n,a[10001],ans;
int main()
{
	cin>>n;
	n*=2;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i+=2) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
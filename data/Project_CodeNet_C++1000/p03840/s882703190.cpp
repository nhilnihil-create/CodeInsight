#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)

int main()
{
	//freopen("1.in","r",stdin);
	s64 a[7];
	rep(i,0,6)cin>>a[i];
	if(!a[0]||!a[3]||!a[4])cout<<a[1]+a[0]/2*2+a[3]/2*2+a[4]/2*2;
	else
		cout<<a[1]+a[0]+a[3]+a[4]-(a[0]%2!=a[3]%2||a[3]%2!=a[4]%2);
}
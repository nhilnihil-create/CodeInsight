#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
string s1,s2;
int a[100005],b[100005],n,m,q,i,j;
int main()
{
	cin>>s1>>s2>>q;n=s1.size();m=s2.size();
	rep(i,n) a[i]=a[i-1]+(s1[i-1]=='A'?1:2);
	rep(i,m) b[i]=b[i-1]+(s2[i-1]=='A'?1:2);
	while(q--)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		cout<<((a[r1]-a[l1-1])%3==(b[r2]-b[l2-1])%3?"YES\n":"NO\n");
	}
	return 0;
}
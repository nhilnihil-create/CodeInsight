#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
const s64 U=1e16+100;
#define rep(i,l,r) for(int i=l;i<=r;++i)
s64 a[55];

int main()
{
	s64 k;
	cin>>k;
	int n=50;
	s64 l=k/(n+1),r=(k+U)/(n+1);
	cout<<n<<endl;
	s64 s=k;
	rep(i,1,n)
	{
		s64 x=min(r,s-(n-i)*l);
		cout<<x*(n+1)-k+n-1<<" ";
		s-=x;
	}
}
#include<bits/stdc++.h>
using namespace std;
long long n,a,b,y,x,a1,a2,s;
int main()
{
	cin>>n>>a>>b;
	cin>>y;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		a1=abs(y-x)*a;a2=b;
		s+=min(a1,a2);
		y=x;
	}
	cout<<s<<"\n";
	return 0;
}
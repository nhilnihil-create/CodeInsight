#include<bits/stdc++.h>
using namespace std;
int v[1000],n,s,a,b,c,i;
int main()
{
	cin>>n;
    for(i=1;i<=n;i++)
    {
    cin>>v[i];
    s+=v[i];
	}
	s/=n;
	for(i=1;i<=n;i++)
	{
		a+=(v[i]-s+1)*(v[i]-s+1);
		b+=(v[i]-s)*(v[i]-s);
		c+=(v[i]-s-1)*(v[i]-s-1);
	}
	cout<<min(min(a,b),c);
}
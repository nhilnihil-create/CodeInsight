#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int x[maxn],ww[maxn],w[maxn];
int l,r,s,t,n,m;
long long c=0;
int main()
{
	cin>>n>>l>>t;
	for(int i=1;i<=n;i++)
	cin>>w[i]>>x[i]; 
	for(int i=1;i<=n;i++)
	{
		if(x[i]==2)x[i]=-1;
		r=w[i]+x[i]*t;
        if (r>0) (c+=r/l)%=n;
        else if (r<0) (c+=(r+1)/l-1)%=n;
        ww[i]=(r%l+l)%l;
	}
	sort(ww+1,ww+n+1);
	c=(c+n)%n;
	for(int i=c+1;i<=n;i++)
	cout<<ww[i]<<endl;
	for(int i=1;i<=c;i++)
	cout<<ww[i]<<endl;
}
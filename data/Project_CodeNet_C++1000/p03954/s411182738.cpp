#include <iostream>
#include <cstdio>
using namespace std;
int n,a[200005],f[200005];
bool check(int x)
{
	for(int i=1;i<=2*n-1;i++)
	{	
	  if(a[i]>x)f[i]=1;
	  else f[i]=0;
	}
    for(int i=1;i<=n;i++)
    {
    	 if(f[n-i]==f[n-i+1])
    	 {
    	 	if(f[n-i]==0)return 0;
    	 	else return 1;
		 }
    	 if(f[n+i]==f[n+i-1])
    	 {
    	    if(f[n+i]==0)return 0;
    	 	else return 1;	
		 }
    }
    if(f[1]==0)return 0;
    return 1;
}
int main()
{

	int maxx=0;
	cin>>n;
	for(int i=1;i<=2*n-1;i++)
	{	scanf("%d",&a[i]);
	    if(a[i]>maxx)maxx=a[i];
	}
	int l=1,r=maxx;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}
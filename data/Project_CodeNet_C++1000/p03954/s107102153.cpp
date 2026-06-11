#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005],n,ans1,ans2,k,maxx=0;
bool cheak(int x)
{
	int ans1=1e8,ans0=1e8;
	for(int i=1;i<=n*2-1;i++) 
	 if(a[i]<x) c[i]=0;else c[i]=1;
    for(int i=1;i<=n*2-2;i++) 
    if(c[i]==c[i+1])
	{
     	 if(c[i])ans1=min(ans1,min(abs(n-i),abs(n-(i+1))));
     	 else ans0=min(ans0,min(abs(n-i),abs(n-(i+1))));
    }
    if(ans1==1e8&&ans0==1e8) return (n&1)==c[n];
	else return ans1<ans0; 
}
int main()
{
	//freopen("pyramid.in","r",stdin);
	//freopen("pyramid.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n*2-1;i++)cin>>a[i];
   int l=-1,r=1e8;
   while(r-l>1)
   {
   	int mid=l+r>>1;
   	if(cheak(mid)) l=mid;
   	else r=mid;
   }
   cout<<l;
}
#include<bits/stdc++.h>
#define maxn 5050
using namespace std;
int n,k,s;
int a[maxn],f[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	 scanf("%d",&a[i]),a[i]=min(a[i],k),s+=a[i];
	sort(a,a+n+1);
	f[0]=1;
	for(int i=n;i>=0;i--)
	 {
	  bool flag=true;
	  for(int j=k-1;j>=k-s&&j>=0;j--)
	   if(f[j])
	    flag=false;
	  if(flag)
	   {
	   	printf("%d\n",i);
	   	break;
	   }
	  for(int j=k;j>=a[i];j--)
	   f[j]|=f[j-a[i]];
	  s-=a[i];
	 }
	return 0;
}

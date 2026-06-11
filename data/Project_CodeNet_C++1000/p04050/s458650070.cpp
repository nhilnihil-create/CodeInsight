#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,a[110];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  scanf("%d",&a[i]);
	if(m==1 && n>1)
	  {
	   printf("%d\n2\n%d 1\n",n,n-1);
	   return 0;
	  }
	for(i=1;i<=m;i++)
	  if(a[i]&1)
	    {
   	     swap(a[1],a[i]);
	     break;
		}
	for(i=2;i<=m;i++)
	  if(a[i]&1)
	    {
	     swap(a[m],a[i]);
	     break;
		}
	for(i=2;i<m;i++)
	  if(a[i]&1)
	    break;
	if(i<m)
	  printf("Impossible\n");
	else
	  {
	   for(i=1;i<=m;i++)
	     printf("%d ",a[i]);
	   printf("\n");
	   a[1]++;
	   a[m]--;
	   if(!a[m])
	     m--;
	   printf("%d\n",m);
	   for(i=1;i<=m;i++)
	     printf("%d ",a[i]);
	   printf("\n");
	  }
	return 0;
}

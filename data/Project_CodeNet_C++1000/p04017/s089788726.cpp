#include <bits/stdc++.h>
using namespace std;
int n,x[100010],L,f[100010][22],Q,g[100010][22];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	scanf("%d",&L);
	int k=1; 
	for (int i=1;i<=n;i++) {
	  while (x[k]-x[i]<=L&&k<=n) k++;
	  f[i][0]=k-1;
    }
    k=n;
    for (int i=n;i;i--) {
    	while (x[i]-x[k]<=L&&k>=1) k--;
    	g[i][0]=k+1;
    }
    for (int i=1;i<=20;i++)
      for (int j=1;j<=n;j++)
        f[j][i]=f[f[j][i-1]][i-1],g[j][i]=g[g[j][i-1]][i-1];
    scanf("%d",&Q);
    for (int i1=1;i1<=Q;i1++) {
    	int a,b;
    	int ans=0;
    	scanf("%d%d",&a,&b);
    	if (a<b) {
    		for (int i=20;i>=0;i--)
    	  	  if (f[a][i]<b) ans+=1<<i,a=f[a][i];
    		ans++;
    	}
    	else {
    		for (int i=20;i>=0;i--)
    		  if (g[a][i]>b) ans+=1<<i,a=g[a][i];
    		ans++;
    	}
    	printf("%d\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
#define N 100005
#define M 105
using namespace std;
int n,m,c,a[M];
void GG(){ printf("Impossible"); exit(0);}
int main()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]),c+=(a[i]&1);
	if(n==1){ printf("1\n1\n1"); return 0;}
	if(m==1){
			printf("%d\n2\n%d %d",n,1,n-1);
			return 0;
		  }
	if(n%2==1&&c>1) GG();
	if(n%2==0&&c>2) GG();
	sort(a+1,a+m+1);
	if(n%2==0&&c==2){
		for(i=1;i<=n;i++) if(a[i]&1) break;
		while(i>1) swap(a[i],a[i-1]),i--;
		for(i=2;i<=n;i++) if(a[i]&1) break;
		while(i<m) swap(a[i],a[i+1]),i++;
	  }
	if(n&1){
		for(i=1;i<=n;i++) if(a[i]&1) break;
		while(i>1) swap(a[i],a[i-1]),i--;
	  }
	for(i=1;i<=m;i++) printf("%d ",a[i]);
	a[1]--,a[m]++;
	printf("\n%d\n",m-(a[1]==0));
	for(i=1;i<=m;i++)
		if(a[i]) printf("%d ",a[i]);
	return 0;
}

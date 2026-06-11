#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int bl=2000;
const char ch[11]="RYGB";
int i,j,k,n,m,a[611][611],b[5101],c[5101],w;
int main(){
	scanf("%d%d%d",&n,&m,&w);memset(b,0,sizeof(b));memset(c,0,sizeof(c));
	for (i=2;i<=n+m;i++)
	 if (i-w>=2) b[i]=b[i-w]^1;else b[i]=0;
	for (i=1-m;i<=n-1;i++)
	 if (i-w>=1-m) c[i+bl]=c[i-w+bl]^1;else c[i+bl]=0;
	for (i=1;i<=n;i++)
	 for (j=1;j<=m;j++){
	 	k=b[i+j]*2+c[i-j+bl];
	 	putchar(ch[k]);
	 	if (j==m) puts("");
	 }
	return 0;
}
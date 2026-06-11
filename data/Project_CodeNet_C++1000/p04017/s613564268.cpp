#include <cstdio>
const int N=100005;
#define ll long long
ll a[N];
int nxt[N][18];
int main (){
	int n;scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%d",&a[i]);
	int L,q;scanf ("%d%d",&L,&q);
	int lst=n;
	for (int i=n;i>=1;i--){
		while (a[lst]-a[i]>L) --lst;
		nxt[i][0]=lst;
	}
	for (int j=1;j<=16;j++)
		for (int i=1;i<=n;i++)
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	while (q--){
		int x,y,ans=0;scanf ("%d%d",&x,&y);if (x>y) x^=y^=x^=y;
		for (int j=16;j>=0;j--)
			if ((nxt[x][j])&&(nxt[x][j]<y)) x=nxt[x][j],ans+=(1<<j);
		printf ("%d\n",ans+1);
	}
	return 0;
}

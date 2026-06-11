#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2e5;
int a[N+3];
int n,m;

int main()
{
	scanf("%d%d",&n,&m); int cnt = 0;
	for(int i=1; i<=m; i++) {scanf("%d",&a[i]); cnt += (a[i]&1);}
	if(m==1)
	{
		if(a[1]==1) printf("1\n1\n1\n");
		else printf("%d\n2\n%d %d\n",a[1],1,a[1]-1);
		return 0;
	}
	else if(m==2)
	{
		if(a[1]==1 && a[2]==1) {printf("1 1\n1\n2\n");}
		else if(a[1]==1) {printf("1 %d\n1\n%d\n",a[2],n);}
		else {printf("%d %d\n2\n%d %d\n",a[1],a[2],a[1]-1,a[2]+1);}
		return 0;
	}
	if(cnt>2) {printf("Impossible"); return 0;}
	if(cnt==1)
	{
		for(int i=1; i<=m; i++) if(a[i]&1) {swap(a[i],a[1]); break;}
	}
	else
	{
		int flag = 0;
		for(int i=1; i<=m; i++) if(a[i]&1) {flag++; if(flag==1) swap(a[i],a[1]); else {swap(a[i],a[m]); break;}}
	}
	for(int i=1; i<=m; i++) printf("%d ",a[i]); puts("");
	printf("%d\n",a[1]==1 ? m-1 : m);
	if(a[1]>1) printf("%d ",a[1]-1);
	for(int i=2; i<=m; i++) printf("%d ",a[i]+(i==m?1:0)); puts("");
	return 0;
}
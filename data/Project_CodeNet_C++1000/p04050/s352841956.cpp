#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int N=110;
int a[N],b[N];
int k1[N],k2[N];
int cnt1,cnt2,cnt;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int n,m,i;
	scanf("%d%d",&n,&m);
	rep(i,1,m)	scanf("%d",&a[i]);
	if(m==1){
		if(n==1)	printf("1\n1\n1\n");
		else printf("%d\n2\n%d 1\n",a[1],a[1]-1);
		return 0;
	}
	rep(i,1,m){
		if(a[i]&1)	k1[++cnt1]=a[i];
		else k2[++cnt2]=a[i];
	}
	if(cnt1>2)	{printf("Impossible\n");return 0;}
	if(cnt1)	b[++cnt]=k1[1];
	rep(i,1,cnt2)	b[++cnt]=k2[i];
	if(cnt1>1)	b[++cnt]=k1[2];
	rep(i,1,cnt)	printf("%d ",b[i]);
	printf("\n");
	b[1]++;b[cnt]--;if(!b[cnt])	cnt--;
	printf("%d\n",cnt);
	rep(i,1,cnt)	printf("%d ",b[i]);
}
	
	
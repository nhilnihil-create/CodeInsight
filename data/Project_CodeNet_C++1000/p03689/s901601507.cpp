#include<cstdio>
#define neko 510
#define f(i,a,b) for(register int i=(a);i<=(b);i=-(~i))
int n,m,h,w,a[neko][neko],sum,p=2333;
int main()
{
	//特殊点是h*w的时候，普通点的1权重较小，当特殊点数大于后面多余的格子个数的时候就凉了
	scanf("%d%d%d%d",&n,&m,&h,&w);
	for(register int i=h;i<=n;i+=h)
	 for(register int j=w;j<=m;j+=w)
	  a[i][j]=-(h*w-1)*p-1;
	f(i,1,n)
	 f(j,1,m)
	  if(!a[i][j])a[i][j]=p,sum+=p;
	  else sum+=a[i][j];
	if(sum<=0)return printf("No\n"),0;
	printf("Yes\n");
	f(i,1,n)
	 f(j,1,m)printf("%d%c",a[i][j],j^m?' ':'\n');
}
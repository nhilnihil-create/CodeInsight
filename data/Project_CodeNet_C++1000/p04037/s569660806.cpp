#include<cstdio>
#include<algorithm>
#define neko 100010
#define f(i,a,b) for(register int i=(a);i<=(b);i=-(~(i)))
#define rf(i,a,b) for(register int i=(a);i>=(b);i=~(-(i)))
int a[neko],ans,n;
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d",&n);
	f(i,1,n)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1,cmp);
	f(i,0,n)
	{
		if(i+1>a[i+1])
		{
			f(j,i+1,n)if(a[j]==i)++ans;
			if(ans&1)return printf("First\n"),0;
			return printf("%s",(a[i]-i)&1?"First":"Second"),0;
		}
	}
}
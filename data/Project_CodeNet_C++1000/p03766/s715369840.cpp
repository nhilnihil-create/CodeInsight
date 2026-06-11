//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define mdn 1000000007
#define N 1000100
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
int f[N],n;
void upd(int &x,int y){x+=x+y>=mdn?y-mdn:y;}
int main()
{
	n=read(); f[n]=n; f[n-1]=1ll*n*n%mdn;
	for(int i=n-2,s=0;i>0;i--)	upd(s,f[i+3]),f[i]=(s+1ll*(n-1)*(n-1)+f[i+1]+i+1)%mdn;
	printf("%d\n",f[1]);
	return 0;
}
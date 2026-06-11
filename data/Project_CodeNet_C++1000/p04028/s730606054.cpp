#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define CL fclose(stdin),fclose(stdout)
namespace io
{
	int F()
	{
		int n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
	long long G()
	{
		long long n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
}
char s[5555];
const int M=1000000007;
int f[5005][5005];
int g[5005][5005];
int h[5005];
int main()
{
	int n=io::F();
	scanf("%s",s+1); 
	int m=strlen(s+1);
	g[1][0]=1,g[1][1]=2;
	for(register int i=1;i<5000;++i)
		for(register int j=0;j<=5000;++j)
			g[i+1][j+1]=(g[i+1][j+1]+2ll*g[i][j])%M,g[i+1][j?j-1:0]=(g[i+1][j?j-1:0]+g[i][j])%M;
	h[0]=1;
	for(register int i=1;i<=5000;++i)
	h[i]=g[i][0];
	f[1][1]=1;
	for(register int i=1;i<5000;++i)
		for(register int j=1;j<=5000;++j)
			f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%M,f[i+1][j-1]=(f[i+1][j-1]+2ll*f[i][j])%M;
	int ans=0;
	for(register int k=0;k<n;++k)
		ans=(ans+(long long)h[k]*f[n-k][m])%M;
	printf("%d\n",ans);
	return 0;
}


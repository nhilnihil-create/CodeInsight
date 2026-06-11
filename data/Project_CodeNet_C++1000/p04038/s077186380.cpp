#include<bits/stdc++.h>
const long long N=2000+10;
const long long P=1e9+7;
using namespace std;

long long n,k,f[N][N];
long long fac[N*N],inv[N*N],fai[N*N],ma;

long long read()
{
	long long a,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
	  if(c=='-') f=-1;
	  c=getchar();
	}
	a=c-'0';
	c=getchar();
	while(c>='0'&&c<='9')
	{
	  a=a*10+c-'0';
	  c=getchar();
	}
	return a*f;
}

long long qpow(long long x,long long b)
{
	long long y;
	if(b==0) return 1;
	if(b==1) return x;
	y=qpow(x,b/2)%P;
	y=y*y%P;
	if(b%2) y=y*x%P;
	return y;
}

int main()
{
	long long i,j,s,t;
	n=read(); k=read();
	if(k==1){printf("1\n"); return 0;}
	ma=n*k;
	fac[0]=inv[0]=fai[0]=1;
	fac[1]=inv[1]=fai[1]=1;
	for(i=2;i<=ma;i++)
	{
	  fac[i]=(fac[i-1]*i)%P;
	  inv[i]=(P-P/i)%P*inv[P%i]%P;
	  fai[i]=fai[i-1]*inv[i]%P;
	}
//	for(i=1;i<=n;i++) cout<<inv[i]<<" ";
//	cout<<endl;
	for(i=0;i<=n;i++) f[i][0]=1;
	for(i=1;i<=n;i++)
	  for(j=1;j<=i;j++)
	  {
	  	f[i][j]=f[i-1][j]%P;
	  	s=((n-i)%P+((n-j+1)*(k-1)%P)-1)%P;
	  	t=(fac[s]*fai[k-2]%P)*fai[s-k+2]%P;
	  	f[i][j]=(f[i][j]+(t*f[i][j-1]%P)*(n-j+1)%P)%P;
	  }
/*	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=i;j++) cout<<f[i][j]<<" ";
	  cout<<endl;
	}*/
	printf("%d\n",f[n][n]);
	return 0;
}
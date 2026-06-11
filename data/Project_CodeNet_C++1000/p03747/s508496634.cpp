#include <bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int A[N],n,L,T,t,cnt,W[N];
signed main()
{
	n=read(); L=read(); T=read();
	for(int i=0;i<n;i++) A[i]=read(), W[i]=read();
	for(int i=0;i<n;i++)
	{
		A[i]+=(W[i]==1? 1:-1)*T;
		(t+=A[i]/L)%=n; A[i]%=L;
		if(A[i]<0) t--,A[i]+=L;
	}
	sort(A,A+n);
	for(int i=0;i<n;i++) printf("%lld\n",A[((t+i)%n+n)%n]%L);  
	return 0;
}
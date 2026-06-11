#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-ff;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(long long aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar(aa%10+'0');
	return;
}
const int mod=1e9+7;
long long n,F[1000005],S[1000005];
int main()
{
	n=read();F[0]=1;S[0]=1;
	for(int i=1;i<=n;++i) 
	{
		if(i>=3) F[i]=(F[i-1]+S[i-3])%mod;
		else F[i]=F[i-1];
		S[i]=(S[i-1]+F[i])%mod;
	}
	write((S[n-2]*(n-1)%mod*(n-1)%mod+(n-1)*S[n-1]%mod+1)%mod);
	return 0;
}
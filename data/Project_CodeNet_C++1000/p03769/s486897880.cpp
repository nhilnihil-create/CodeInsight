#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
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
long long n,len,qwq,now;
long long emm;
long long a[205];
int main()
{
	n=read();
	for(long long i=1;i<=41;++i) if((1ll<<i)>n) break;else qwq=i;
	now=qwq;emm++;
	n-=(1ll<<qwq);
	if(n&1) now++,a[++len]=now;
	for(long long i=1;i<=qwq;++i)
	{
		a[++len]=i;
		if(n&(1ll<<i)) now++,a[++len]=now;
	}
	for(long long i=1;i<=qwq;++i) a[++len]=i;//cout<<"111"<<endl;
	for(long long i=now;i>qwq;--i) a[++len]=i;
	for(long long i=1;i<=emm;++i) now++,a[++len]=now,a[++len]=now;
	write(len);puts("");
	for(long long i=1;i<=len;++i) write(a[i]),putchar(' ');
	return 0;
}
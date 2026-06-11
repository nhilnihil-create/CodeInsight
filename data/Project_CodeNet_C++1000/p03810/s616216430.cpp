#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
typedef long long LL;
const int N=100005;
int n,a[N];
int GCD(int x,int y) {return y?GCD(y,x%y):x;}
int work() {
	LL sum=0;int js=0,x,gcd;
	for(RI i=1;i<=n;++i) {
		sum+=a[i]-1;
		if((a[i]&1)&&a[i]!=1) ++js,x=i;
	}
	if(sum&1) return 1;
	if(js!=1) return 0;
	--a[x],gcd=a[1];
	for(RI i=2;i<=n;++i) gcd=GCD(gcd,a[i]);
	for(RI i=1;i<=n;++i) a[i]/=gcd;
	return work()^1;
}
int main()
{
	n=read();
	for(RI i=1;i<=n;++i) a[i]=read();
	if(work()) puts("First");
	else puts("Second");
	return 0;
}
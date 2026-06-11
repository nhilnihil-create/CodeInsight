#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 100050
using namespace std;
LL read(){
	LL nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL gcd(LL x,LL y){return y==0?x:gcd(y,x%y);}
LL n,p[M],G[M],F[M],sq[31];
void win(LL x){puts(x?"Second":"First");exit(0);}
void solve(LL now){
	LL pos=0,sum=0,m=0,tot=0;
	for(LL i=1;i<=n;i++) sum+=p[i],m+=(p[i]&1),pos+=(p[i]&1)*i;
	if((sum&1)^(n&1)) win(now);
	else if(p[1]==1||m>1) win(now^1);
	for(LL i=1;i<=n;i++) tot=gcd(tot,p[i]-(p[i]&1));
	for(LL i=1;i<=n;i++) p[i]=(p[i]-(p[i]&1))/tot;
	solve(now^1);
}
int main(){
	n=read(),sq[0]=1;
	for(LL i=1;i<31;i++) sq[i]=sq[i-1]*2ll;
	for(LL i=1;i<=n;i++) p[i]=read();
	sort(p+1,p+n+1),solve(0);
	return 0;
}
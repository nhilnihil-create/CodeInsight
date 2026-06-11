#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(l,r,i) for(int i=l;i>=r;i--)
using namespace std;

typedef long long LL;
const int INF =2147483647;
int qread(){
	int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =1e5 +3;
int n,A,B,h[MAXN],ans;
bool check(LL t){
	LL t_=0;
	up(1,n,i) if(h[i]<=t*B) continue;
	else t_+=(LL)ceil((double)(h[i]-t*B)/(A-B));
	return t_<=t;
}
LL calc(){
	LL p=0,k=1;
	while(k){
		if(!check(p+k)) p+=k,k<<=1;
		else k>>=1;
	}
	return p+1;
}
int main(){
	n=qread(),A=qread(),B=qread();
	up(1,n,i) h[i]=qread();
	printf("%lld\n",calc());
	return 0;
}

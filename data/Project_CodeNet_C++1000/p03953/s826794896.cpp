#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005
#define LL long long
#define rep(i,j,k) for(i=j;i<=k;++i)
LL n,m,i,j,K;
LL x[N],d[N],to[N],tmp[N],sum[N];
void read(LL &p){
	p=0; char x=getchar(); bool fu=false;
	if(x=='-') fu=true;
	while(x<'0' || x>'9'){x=getchar(); if(x=='-') fu=true;}
	while(x>='0'&&x<='9'){p=p*10+x-'0'; x=getchar();}
	if(fu) p=-p;
}
void quick_mi(LL b){
	for(;b;b>>=1){
		if(b&1){
			rep(i,1,n) sum[i]=to[sum[i]];
		}
		rep(i,1,n) tmp[i]=to[i];
		rep(i,1,n) to[i]=tmp[to[i]];
	}
}
int main(){
	read(n);   
	rep(i,1,n){
		read(x[i]);
		d[i]=x[i]-x[i-1];
		sum[i]=tmp[i]=to[i]=i;
	}
	read(m); read(K);
	rep(i,1,m){
		read(j);
		swap(tmp[j],tmp[j+1]); 
	}
	rep(i,1,n) to[tmp[i]]=i;
	quick_mi(K);
	rep(i,1,n) x[sum[i]]=d[i];
	rep(i,1,n){
		x[i]+=x[i-1];
		printf("%lld\n",x[i]);
	}
	return 0;
}
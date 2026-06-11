#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
ll i,j,l,k,t,n,m,ans,an[maxn];
ll a[maxn],b[maxn],c[maxn],x,d[maxn],e[maxn];
void gao(ll *x,ll *y){
    ll i;
    fo(i,1,n)d[i]=x[y[i]];
    fo(i,1,n)x[i]=d[i];
}
int main(){
//	freopen("fan.in","r",stdin);
    scanf("%lld",&n);
    fo(i,1,n)scanf("%lld",&a[i]),a[i]=a[i]-x,x=a[i]+x,b[i]=c[i]=e[i]=i;
    scanf("%lld%lld",&m,&k);
    fo(i,1,m)scanf("%lld",&l),swap(b[l],b[l+1]);
    for(;k;k/=2,gao(b,b)){
    	if(k&1)gao(e,b);
	}
	x=0;fo(i,1,n)x+=a[e[i]],printf("%lld.0\n",x);
}
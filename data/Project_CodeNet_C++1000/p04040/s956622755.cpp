#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define ll long long
const int P=1e9+7,maxn=1e6;
ll h,w,a,b,ans,D[maxn],U[maxn];
ll q_pow(ll a,ll b){
    ll ret=1;
    while(b){
        if (b&1) ret=ret*a%P;
        a=a*a%P;
        b>>=1;
    }
    return ret;
}
ll C(ll n,ll m){
    return U[n]*D[m]%P*D[n-m]%P;
}
int main() {
    U[0]=D[0]=1;
    for (int i=1; i<maxn; i++){
        U[i]=U[i-1]*i%P;
        D[i]=q_pow(U[i],P-2);
    }
	scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
	ll x=h-a;
    for (int i=b+1; i<=w; i++)
        ans=(ans+C(h-a+i-2,i-1)*C(a-1+w-i,a-1))%P;
	printf("%lld\n",ans);
}
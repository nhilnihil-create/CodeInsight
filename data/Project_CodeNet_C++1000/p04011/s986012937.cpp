#pragma GCC Optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i,begin,end) for (int i=begin;i<end;i++)
const int N=30,M=N*N,OO=0x3f3f3f3f;
int main(){
    ll n,x,y,sum=0, k;
    scanf("%lld%lld%lld%lld",&n,&k,&x,&y);
    sum+=min(n,k)*x;
    n-=k;
    if(n>0)sum+=n*y;
    printf("%lld",sum);
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3+5;
ll solve(ll x,ll y){
    //printf("x:%lld y:%lld\n",x,y);
    if(x<y)return solve(y,x);
    if(y==0)return x;
    return 2*((x-1)/y)*y+solve(y,x%y);
}
int main()
{
    ll n,x,y;
    scanf("%lld%lld",&n,&x);
    printf("%lld\n",n+solve(x,n-x));
    return 0;
}

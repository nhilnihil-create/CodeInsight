#include <cstdio>
#include <cstring>
typedef long long ll;
int main(){
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    ll l = 1LL*a*(n-1) + b,r = 1LL*b*(n-1) + a;
    if(l > r) {puts("0");return 0;}
    else printf("%lld\n",(r-l+1));
    return 0;
}
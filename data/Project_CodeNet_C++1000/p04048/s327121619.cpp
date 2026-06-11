#include <cstdio>
using namespace std;
long long n,x;
long long sol(long long x,long long n){
    if(n%x==0) return n*2-x;
    return n/x*x*2+sol(n%x,x);
}int main(){while(~scanf("%lld%lld",&n,&x))printf("%lld\n",sol(x,n-x)+n);}
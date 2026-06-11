#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
 
LL N, X;
 
LL f(LL a, LL b){
    if (a <= 0 || b <= 0) return 0;
    if (a%b == 0) return ((a+b)/b-1)*2*b;
    LL c = (a+b)%b;
    return (a+b)/b*b*2 + (b-1)/c*c + f(c - (b%c), b%c);
}
 
int main(){
    scanf("%lld %lld", &N, &X);
    if (X > N-X) printf("%lld", X+f(X, N-X));
    else printf("%lld\n", N+X+f(N-2*X, X));
    return 0;
}
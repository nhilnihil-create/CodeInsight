#include <bits/stdc++.h>
using namespace std;
long long f(long long a, long long b){
    if(b == 0) return -a;
    if(a >= b) return f(b, a%b) + 2*b*(a/b);
    return f(b, a%b);
}
int main(){
    long long n, x;
    scanf("%lld%lld", &n, &x);
    printf("%lld\n", n + f(n-x, x));
}
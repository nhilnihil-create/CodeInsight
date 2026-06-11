// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, x;
    scanf("%lld%lld", &n, &x);
    return !printf("%lld\n", 3LL * (n - __gcd(n, x)));
}
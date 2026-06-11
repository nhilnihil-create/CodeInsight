#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b;

int main() {
    scanf("%lld%lld%lld", &n, &a, &b);
    if((n == 1 && a != b) || a > b) printf("0\n");
    else if(a == b) printf("1\n");
    else printf("%lld\n", ((n - 1) * b + a) - ((n - 1) * a + b) + 1);
}
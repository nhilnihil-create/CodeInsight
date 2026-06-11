#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    scanf("%d", &N);
    ll res = -1, B = 1e9+10;
    for(int i = 0; i < N; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        if(res < a) res = a, B = b;
    }
    printf("%lld\n", res + B);
    return 0;
}
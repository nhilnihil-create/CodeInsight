#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = (a), i_len = (b); i < b; ++i)

int main()
{
    int N; ll A, B;
    scanf("%d %lld %lld", &N, &A, &B);
    int X[N+3];
    REP(i, 0, N) scanf("%d", &X[i]);

    ll res = 0;
    REP(i, 1, N) {
        ll dis = X[i] - X[i-1];
        res += min(dis*A, B);
    }
    printf("%lld\n", res);
    return 0;
}
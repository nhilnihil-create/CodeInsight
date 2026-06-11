#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N; ll K;
    scanf("%d %lld", &N, &K);
    ll a[N];
    for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);
    sort(a, a + N);
    ll sm = 0;
    int res = N;
    for(int i = N-1; i >= 0; --i) {
        if(sm + a[i] < K) sm += a[i];
        else res = min(res, i);
    }
    printf("%d\n", res);
    return 0;
}
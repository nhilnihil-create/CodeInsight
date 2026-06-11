#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;

ll N, A, B, C, D;

int main() {
    scanf("%lld %lld %lld %lld %lld", &N, &A, &B, &C, &D);
    N--;
    ll L = N * C, R = N * D;
    ll diff = R - L;
    ll target = abs(B - A) + R;
    ll s = C + D;
    printf("%s", target <= --N * s + diff && target % s <= diff ? "YES" : "NO");
	return 0;
}
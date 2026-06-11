#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(int _##i = (t), i = (f); i <  _##i; i++)
#define downto(f, t, i)  for(int _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(int _##i = (t), i = (f); i >  _##i; i--)
typedef long double LD;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define ln << endl
#else
#define debug false
#define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '

#define lam [&]


signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    long K; scanf("%lld", &K);

    int N = 50;
    cout << N ln;
    long a = 49 + K / 50 - K % 50;
    times(N, i) {
        cout << (i < K % 50 ? a + 51 : a) sp;
    }

    return 0;
}

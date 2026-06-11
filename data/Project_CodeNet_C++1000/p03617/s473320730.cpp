#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    if (2 * Q < H)
        H = 2 * Q;
    if (2 * H < S)
        S = 2 * H;
    if (2 * S < D)
        D = 2 * S;

    cout << (D * (N / 2)) + (S * (N % 2)) << endl;
}
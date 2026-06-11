#include "bits/stdc++.h"
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = 1e9;
const LL LLINF = 1e18;

void solve()
{
    LL X;
    cin >> X;

    // 最適解は 1..k までの整数の任意を選んで
    // 和をXとできるような k のうち最小のもの
    // つまりある k が存在して 1..k の和がXに一致すればそのkが答えであり,
    // 一致しなければ, 和がXを超える最も小さいkが答え.
    // (何もしないを適切な場所に挟めば良い)
    LL n = (-1 + sqrt(1 + 8 * X)) / 2;

    cout << n + ((n * (n + 1)) / 2 != X) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
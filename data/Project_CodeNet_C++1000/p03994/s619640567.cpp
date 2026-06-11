#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)

void solve()
{
    // 次の文字への変換は, z -> a 以外常に悪くなる
    // 各文字で 'z'-c 回使って 'a' にするか, 何もしないかの二択
    // 先頭から'a'に変えられればかえる, できなければスルーする
    // 余ったら最後の文字で使えばよい

    string S;
    cin >> S;
    int K;
    cin >> K;

    REP0 (i, S.length())
    {
        if (S[i] == 'a')
            continue;

        int cost_i = 'z' - S[i] + 1;
        if (cost_i <= K)
        {
            K -= cost_i;
            S[i] = 'a';
        }
    }

    if (K > 0)
    {
        int n = S.back() - 'a';
        n += K;
        n %= 26;
        S.back() = char(n + 'a');
    }

    cout << S << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}

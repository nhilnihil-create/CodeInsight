#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
#define PRYES(x) PR((x) ? "Yes" : "No")
const long long INF = numeric_limits<long long>::max();
// SourceTest用出力マクロ
#ifdef SOURCE_TEST
#define SPR(x) PR(x)
#define SPS(x) PS(x)
#else
#define SPR(x) \
    {}
#define SPS(x) \
    {}
#endif
int main() {
    string str;
    cin >> str;

    string ans;

    for (ll i = 0; i < str.size(); ++i) {
        switch (str[i]) {
            case '0': ans += '0'; break;
            case '1': ans += '1'; break;
            case 'B':
                if (ans.size() > 0) {
                    ans.erase(ans.size() - 1);
                }
                break;
        }
    }

    PR(ans);
    return 0;
}
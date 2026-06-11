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
    map<char, string> cards;
    cin >> cards['a'];
    cin >> cards['b'];
    cin >> cards['c'];

    char turn = 'a';

    while (1) {
        if (cards[turn].size() == 0) break;
        auto nextTurn = cards[turn][0];
        cards[turn]   = cards[turn].substr(1, cards[turn].size() - 1);
        turn          = nextTurn;
    }

    turn = toupper(turn);
    PR(turn);
    return 0;
}

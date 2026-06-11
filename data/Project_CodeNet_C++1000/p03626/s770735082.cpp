#include <bits/stdc++.h>

#define REP(i, n) for(decltype(n) i = 0; i < n; i++)

#define ALL(c)   c.begin(), c.end()
#define SORT(c)  std::sort(ALL(c))
#define RSORT(c) std::sort(ALL(c), std::greater<decltype(c)::value_type>())

using namespace std;
using ll = long long;

const int MOD  = (int)1e9 + 7;
const int INF  = (int)1e9 + 1;
const ll  LINF = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    string S1, S2;
    std::cin >> S1 >> S2;

    ll ans = S1[0] == S2[0] ? 3 : 6;
    for(int i = S1[0] == S2[0] ? 1 : 2; i < N; i++) {
        if(S1[i] == S2[i]) {
            if(S1[i - 1] == S2[i - 1]) {
                ans *= 2;
            }
            else {
                ans *= 1;
            }
        }
        else {
            if(S1[i - 1] == S2[i - 1]) {
                ans *= 2;
            }
            else {
                ans *= 3;
            }
            i++;
        }
        ans %= MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}

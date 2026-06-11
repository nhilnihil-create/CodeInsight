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

    string s;
    std::cin >> s;

    int ans   = 0;
    REP(i, s.size()) {
        if(i % 2 == 1) {
            if(s[i] == 'g') ans++;
        }
        else {
            if(s[i] == 'p') ans--;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

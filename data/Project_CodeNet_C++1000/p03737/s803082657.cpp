#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

void solve(std::vector<std::string> s) {
  rep(i, 3) cout << (char)(s[i][0] - ' ');
  cout << endl;
}

int main() {
    std::vector<std::string> s(3);
    for(int i = 0 ; i < 3 ; i++){
        std::cin >> s[i];
    }
    solve(std::move(s));
}

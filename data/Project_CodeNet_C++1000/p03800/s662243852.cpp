#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    rep(i, (int)v.size()) {
        if (i)
            os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
    for (auto val : array)
        std::cout << val << ", ";
    std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    int n; std::cin >> n;
    string s; std::cin >> s;
    string ans(n, '-');
    auto rev = [](char &c) {
        return (c=='S' ? 'W' : 'S');
    };
    rep(i, 1<<2) {
        rep(j, 2) {
            if ((i>>j)&1) ans[j] = 'S';
            else ans[j] = 'W';
        }
        srep(j, 1, n-1) {
            if (ans[j] == 'S')
                ans[j+1] = (s[j]=='o' ? ans[j-1] : rev(ans[j-1]));
            else
                ans[j+1] = (s[j]=='x' ? ans[j-1] : rev(ans[j-1]));
        }
        char c1, c2;
        if (ans[n-1] == 'S')
            c1 = (s[n-1]=='o' ? ans[n-2] : rev(ans[n-2]));
        else
            c1 = (s[n-1]=='x' ? ans[n-2] : rev(ans[n-2]));
        if (ans[0] == 'S')
            c2 = (s[0]=='o' ? ans[1] : rev(ans[1]));
        else
            c2 = (s[0]=='x' ? ans[1] : rev(ans[1]));
        if (c1 == ans[0] && c2 == ans[n-1]) {
            std::cout << ans << "\n";
            return 0;
        }
    }
    std::cout << -1 << "\n";
}

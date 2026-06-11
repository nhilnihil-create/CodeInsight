#include <bits/stdc++.h>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define all(c) begin(c),end(c)

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}


const int INF = 1 << 29;

auto solve() {
    int N;
    cin >> N;
    vi a(N);
    for (auto &&e: a) cin >> e;
    sort(all(a));
    int mn = a[0];
    int mx = a[N - 1];

    map<int, int> nums;
    for (auto &&e: a) nums[e]++;

    if (mx % 2 == 0) {
        if (mx / 2 != mn || nums[mn] != 1)
            return false;
    } else {
        if ((mx + 1) / 2 != mn || nums[mn] != 2)
            return false;
    }

    FOR(i, mn, mx+1) {
        if(nums[i] == 0)
            return false;
    }

    return true;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << (solve() ? "Possible" : "Impossible") << endl;
//    solve();
    return 0;
}

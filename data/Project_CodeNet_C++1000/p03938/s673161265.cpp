#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    REP(i, n) { cin >> p[i]; }
    vector<int> a(n), b(n);
    int maxi = 40000;
    REP(i, n) {
        a[i] = maxi * (i + 1);
        b[i] = maxi * (n - i - 1) + 1;
    }
    REP(i, n) { a[p[i] - 1] += i; }
    print(a);
    print(b);
    return 0;
}
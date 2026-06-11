#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i,m,n) for (int i = (n)-1; (i) >= (m); --(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
typedef long long ll;
using namespace std;
template <class T> void setmax(T & a, T const & b) { if (a < b) a = b; }
template <class T> void setmin(T & a, T const & b) { if (b < a) a = b; }
template <typename T, typename X> auto vectors(T a, X x) { return vector<T>(x, a); }
template <typename T, typename X, typename Y, typename... Zs> auto vectors(T a, X x, Y y, Zs... zs) { auto cont = vectors(a, y, zs...); return vector<decltype(cont)>(x, cont); }
template <typename T> T input(istream & in) { T a; in >> a; return a; }
int main() {
    // input
    int n, m; cin >> n >> m;
    map<int,int> xs;
    repeat (i,n) {
        int x; cin >> x;
        xs[x] += 1;
    }
    // compute
    vector<int> cnt(m), pr(m);
    for (auto it : xs) {
        int x, k; tie(x, k) = it;
        cnt[x % m] += k;
        pr [x % m] += k / 2 * 2;
    }
    int ans = 0;
    repeat (i,m) {
        int j = (m - i) % m;
        if (i == j) {
            ans += cnt[i] / 2;
        } else if (i < j) {
            int k = min(cnt[i], cnt[j]);
            ans += k;
            ans += min(cnt[i] - k, pr[i]) / 2;
            ans += min(cnt[j] - k, pr[j]) / 2;
        }
    }
    // output
    cout << ans << endl;
    return 0;
}

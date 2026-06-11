#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using bint = boost::multiprecision::cpp_int;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
#define rrepSE(i,s,e) for (int i = (s); i > (e); i--)
#define ssort(v) sort(v.begin(), v.end())
#define gsort(v) sort(v.rbegin(), v.rend())
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
#define DEBUG_PRINT(var) std::cout << #var << " = " << var << "\n";

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

const ll MX = 21001001001;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> v(n);
    rep(i,n) v[i] = i;
    vector<int> sel(k);
    ll ans = MX;
    do {
        rep(i,k) sel[i] = v[i];
        int j = 0;
        ll mxnow = 0, pay = 0;
        rep(i,n) {
            if (sel[j] == i) {
                if (a[sel[j]] <= mxnow) {
                    pay += mxnow - a[sel[j]] + 1;
                    mxnow += 1;
                }
                j++;
            }
            chmax(mxnow, a[i]);
        }
        chmin(ans, pay);
    } while (next_combination(v.begin(), v.end(), k));
    cout << ans << "\n";
    return 0;
}

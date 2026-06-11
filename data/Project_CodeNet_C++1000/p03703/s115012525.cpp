//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi sum(n+1);
    vi num(1);
    rep(i, n) {
        sum[i+1] = sum[i] + a[i] - k;
        num.emplace_back(sum[i+1]);
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());
    rep(i, n+1) {
        auto itr = lower_bound(all(num), sum[i]);
        sum[i] = itr-num.begin();
    }

    vi bits(num.size()+1);
    auto add = [&](int i, int x) {
        while(i <= num.size()) {
            bits[i] += x;
            i += i&-i;
        }
    };
    auto bsum = [&](int i) {
        int res = 0;
        while(i) {
            res += bits[i];
            i &= i-1;
        }
        return res;
    };

    ll ans = 0;
    rep(i, n+1) {
        ans += bsum(sum[i]+1);
        add(sum[i]+1, 1);
    }

    cout << ans << endl;
}
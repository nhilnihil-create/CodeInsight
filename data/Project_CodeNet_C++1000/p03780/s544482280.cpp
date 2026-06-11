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
using vi = vector<int>;
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
    vi a;
    rep(i, n) {
        int aa;
        cin >> aa;
        if(aa >= k) continue;
        a.emplace_back(aa);
    }
    n = a.size();
    if(!n) {
        cout << 0 << endl;
        return 0;
    }
    sort(all(a));
    int l = -1, r = n, mid;
    while(r-l != 1) {
        mid = (l+r)>>1;
        vi dp(k);
        dp[0] = 1;
        rep(i, n) if(i != mid) {
            for(int j = k-1; j >= a[i]; j--) {
                dp[j] += dp[j-a[i]];
            }
        }
        bool ok = false;
        for(int i = k-a[mid]; i < k; i++) {
            if(dp[i]) ok = true;
        }
        if(ok) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}
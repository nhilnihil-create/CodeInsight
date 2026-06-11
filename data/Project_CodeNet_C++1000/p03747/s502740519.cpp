//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, t;
    cin >> n >> l >> t;
    vi one, two;
    vi x(n), w(n);
    rep(i, n) {
        cin >> x[i] >> w[i];
        if(w[i] == 1) one.push_back(x[i]);
        else two.push_back(x[i]);
    }

    int kk = one.size();
    rep(i, kk) one.push_back(one[i] - l);
    rep(i, kk) one.push_back(one[i] - l*2);
    kk = two.size();
    rep(i, kk) two.push_back(two[i] + l);
    rep(i, kk) two.push_back(two[i] + l*2);
    sort(all(one));

    vi ans(n);
    rep(i, n) {
        int xx;
        if(w[i] == 1) {
            xx = (t + x[i])%l;
            if(two.size() == 0) {
                ans[i] = xx;
                continue;
            }
            int num = t/l * (two.size()/3);
            num <<= 1;
            int time = t%l;
            auto itr = upper_bound(all(two), x[i]+time*2);
            auto uitr = lower_bound(all(two), x[i]);
            ans[(i + num + (itr - uitr))%n] = xx;
            //cout << (i + num + (itr - uitr))%n << ' ' << xx << endl;
        } else {
            xx = (x[i] - t%l + l)%l;
            if(one.size() == 0) {
                ans[i] = xx;
                continue;
            }
            int num = t/l * (one.size()/3);
            num <<= 1;
            int time = t%l;
            auto itr = lower_bound(all(one), x[i]-time*2);
            auto uitr = upper_bound(all(one), x[i]);
            ans[(i - num%n - (uitr - itr)%n + 2*n)%n] = xx;
            //cout << (i - num%n - (uitr - itr)%n + 2*n)%n << ' ' << xx << endl;
        }
    }

    rep(i, n) {
        cout << ans[i] << '\n';
    }
}
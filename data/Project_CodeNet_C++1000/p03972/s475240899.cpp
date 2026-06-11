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
    ll w, h;
    cin >> w >> h;
    vector<ll> p(w), q(h);
    rep(i, w) cin >> p[i];
    rep(i, h) cin >> q[i];

    ll ans = 0;
    rep(i, w) {
        ans += ll(h+1)*p[i];
    }
    rep(i, h) {
        ans += ll(w+1)*q[i];
    }

    sort(rall(p));
    sort(rall(q));
    int cntp = 0, cntq = 0;
    ll cnt = 0;
    while(cnt != h*w) {
        if(p[cntp] > q[cntq]) {
            if(cnt + h-cntq > h*w) {
                ans -= p[cntp++]*(h*w-cnt);
                cnt = h*w;
            } else {
                ans -= p[cntp++]*(h-cntq);
                cnt += h-cntq;
            }
        } else {
            if(cnt + w-cntp > h*w) {
                ans -= q[cntq++]*(h*w-cnt);
                cnt = h*w;
            } else {
                ans -= q[cntq++]*(w-cntp);
                cnt += w-cntp;
            }
        }
    }
    cout << ans << endl;
}
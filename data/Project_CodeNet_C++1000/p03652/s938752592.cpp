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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    rep(i, n) rep(j, m) {
        cin >> a[i][j];
        a[i][j]--;
    }
    auto check = [&](int b) {
        vector<queue<int> > q(n);
        vector<bool> used(m);
        rep(i, n) rep(j, m) {
            q[i].push(a[i][j]);
        }
        rep(i, m) {
            vi cnt(m);
            int ma = 0;
            int j = 0;
            rep(i, n) {
                while(used[q[i].front()]) q[i].pop();
                cnt[q[i].front()]++;
                if(chmax(ma, cnt[q[i].front()])) j = q[i].front();
            }
            if(ma <= b) return true;
            used[j] = true;
        }
        return false;
    };
    int aa = 0, b, c = 300;
    while(c-aa > 1) {
        b = (aa+c)/2;
        if(check(b)) {
            c = b;
        } else {
            aa = b;
        }
    }
    cout << c << endl;
}
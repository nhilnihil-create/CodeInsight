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
    string s, t;
    cin >> s >> t;
    vi ss(s.size()+1), tt(t.size()+1);
    rep(i, s.size()) {
        ss[i+1] = ss[i] + (s[i] == 'A');
        ss[i+1] -= (s[i] == 'B');
    }
    rep(i, t.size()) {
        tt[i+1] = tt[i] + (t[i] == 'A');
        tt[i+1] -= (t[i] == 'B');
    }

    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --c;
        //cout << tt[d]-tt[c] << ' ' << ss[a]-ss[b] << '\n';
        cout << ((tt[d]-tt[c]+ss[a]-ss[b])%3 == 0?"YES":"NO") << '\n';
    }
}
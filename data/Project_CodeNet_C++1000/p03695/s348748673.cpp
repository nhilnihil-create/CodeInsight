#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll N; cin >> N;
    map<ll, bool> A;

    ll colorful = 0;
    rep(i, N) {
        ll a; cin >> a;
        if (0 <= a && a <= 399) A[0] = true;
        else if (400 <= a && a <= 799) A[1] = true;
        else if (800 <= a && a <= 1199) A[2] = true;
        else if (1200 <= a && a <= 1599) A[3] = true;
        else if (1600 <= a && a <= 1999) A[4] = true;
        else if (2000 <= a && a <= 2399) A[5] = true;
        else if (2400 <= a && a <= 2799) A[6] = true;
        else if (2800 <= a && a <= 3199) A[7] = true;
        else colorful++;
    }

    ll min = 0, max = colorful;
    rep(i, 8) {
        if (A[i]) {
            min++; max++;
        }
    }
    if (min == 0) cout << 1 << " " << max << endl;
    else cout << min << " " << max << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1e9+7
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int a,b,c,d; cin >> a >> b >> c >> d;
    if (a<=c && c<=b) {
        if (b<=d) cout << b-c << endl;
        else cout << d-c << endl;
        return 0;
    }
    if (c<=a && a<=d) {
        if (d<=b) cout << d-a << endl;
        else cout << b-a << endl;
        return 0;
    }
    cout << 0 << endl;
} 
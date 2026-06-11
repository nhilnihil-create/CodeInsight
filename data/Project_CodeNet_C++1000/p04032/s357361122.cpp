#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s; cin >> s;

    bool ok = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            cout << i << " " << i+1 << endl;
            return 0;
        }
        if (i > 1 && s[i] == s[i-2]) {
            cout << i-1 << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}

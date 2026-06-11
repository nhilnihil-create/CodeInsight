#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v;
    rep(i, n) {
        int a; cin >> a;
        rep(j, a) v.push_back(i+1);
    }

    rep(i, h*w) {
        int row = i / w + 1;
        if ((i / w) % 2 == 0) {
            cout << v[i] << " ";
        } else {
            cout << v[row*w - i%w - 1] << " ";
        }
        if (i % w == w-1) cout << endl;
    }
}

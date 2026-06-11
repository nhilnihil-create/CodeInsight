#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template < typename T > string tost( const T& n ) { ostringstream stm; stm << n; return stm.str();}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;

ll H,W;
ll solve(ll H, ll W) {
    ll res;
    if(H % 3 == 0) res = 0;
    else res = W;
    rrep(h,H) {
        vl S(3);
        S[0] = h * W;
        S[1] = (H - h) * (W/2);
        S[2] = (H - h) * (W - (W/2));
        sort(all(S));
        chmin(res, S[2]-S[0]);
    }
    return res;
}

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

cin >> H >> W;
ll ans = min(solve(H, W), solve(W, H));
cout << ans << endl;

return 0;
}
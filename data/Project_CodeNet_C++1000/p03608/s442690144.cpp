#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;


int main()
{
    int n,m,R;
    cin >> n >> m >> R;
    vi r(R);
    rep(i,R) {
        cin >> r[i];
        r[i]--;
    }
    sort(all(r));
    vvi dist(n,vi(n,INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int res = INF;
    do {
        int sum = 0;
        rep(i,R-1) {
            sum += dist[r[i]][r[i+1]];
        }
        chmin(res, sum);
    } while(next_permutation(all(r)));
    cout << res << endl;
    return 0;
}
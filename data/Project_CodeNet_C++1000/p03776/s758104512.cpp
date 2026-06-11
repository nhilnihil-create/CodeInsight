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

long long com[51][51];


int main()
{
    com[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];        
        }
    }

    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(all(v),greater<ll>());

    ll sum = 0, res = 0;
    rep(i,a) sum += v[i];

    //1種類
    if(v[0] == v[a-1]) {
        ll m = count(all(v), v[0]);
        for(int i = a; i <= b; ++i) res += com[m][i];
    }
    //2種類以上
    else {
        ll m = count(all(v), v[a-1]);
        ll cnt = 0;
        rep(i,a) cnt += (v[i] == v[a-1]);
        res = com[m][cnt];
    }

    cout << fixed << setprecision(10) << (double)sum/(double)a << endl;
    cout << res << endl;


    return 0;
}
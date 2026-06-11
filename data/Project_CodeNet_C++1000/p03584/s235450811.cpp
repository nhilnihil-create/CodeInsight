#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << '\n'
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pr(s) cout << (s) << '\n'
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;
const ll INFll = 1E+18;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    int keta = 0;
    while ((k>>keta)>0) {
        keta++;
    }
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll ans = 0;
    rep(i, keta) {
        if ((k>>i&1)==0) continue;
        ll score = 0;
        rep(j, n) {
            bool ok = true;
            if ((a[j]>>i&1)==1) ok = false;
            rep(l, 30) {
                if (l<=i) continue;
                if ((k>>l&1)==0 && (a[j]>>l&1)==1) ok = false;
            }
            if (ok) score += b[j];
        }
        chmax(ans, score);
    }
    ll res = 0;
    rep(j, n) {
        bool ok = true;
        rep(l, 30) {
            if ((k>>l&1)==0 && (a[j]>>l&1)==1) ok = false;
        }
        if (ok) res += b[j];
    }
    chmax(ans, res);
    
    pr(ans);
    return 0;
}

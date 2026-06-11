#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
const ll INF = (1LL << 60);
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/
/******** User-defined Function *******/

/**************************************/
/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k; cin >> n >> k;

    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll ans = INF;
    rep(bit, (1<<n)){
        if(__builtin_popcount(bit)<k) continue;
        ll cnt = 0;
        ll cost = 0;
        ll h_max = -1;
        rep(i,n){
            if(bit & (1<<i)){
                if(a[i]>h_max){
                    h_max = a[i];
                }else{
                    h_max++;
                    cost += (h_max - a[i]);
                }
                cnt++;
            }else{
                h_max = max(h_max, a[i]);
            }

            if(cnt>=k) break;
        }

        ans = min(ans, cost);
    }

    cout << ans << endl;

}
/********  Main() Ends Here *************/

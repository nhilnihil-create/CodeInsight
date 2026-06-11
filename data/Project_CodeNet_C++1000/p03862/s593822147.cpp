#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11

int main()
{
    ll n,x; cin >> n >> x;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll ans = 0;
    for(int i = 0;i < n-1; i++){
        if(a[i] > x){
            ans += a[i]-x;
            a[i] = x;
        }
        if(a[i] + a[i+1] > x){
            ans += (a[i+1]+a[i]-x);
            a[i+1] = (x - a[i]);
        }
    }
    cout << ans << endl;
}
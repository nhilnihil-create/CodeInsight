#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N; ll A, B;
    cin >> N >> A >> B;
    ll H[N];
    rep(i, N) cin >> H[i];
    ll l = -1, r = 1e10;
    while(r-l > 1){
        ll n = (l+r)/2;
        ll sum = 0;
        rep(i, N){
            if(n*B > H[i]) continue;
            sum += (H[i]-n*B+A-B-1)/(A-B);
        }
        if(sum <= n) r = n;
        else l = n;
    }
    cout << r << endl;
}
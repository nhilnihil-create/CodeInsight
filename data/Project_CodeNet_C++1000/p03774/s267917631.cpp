#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N,0);
    vector<ll> b(N,0);
    vector<ll> c(M,0);
    vector<ll> d(M,0);

    rep(i,N) cin >> a[i] >> b[i];
    rep(i,M) cin >> c[i] >> d[i];

    rep(i,N){
        ll tmp = MOD;
        ll ans;
        rep(j,M){
            if((abs(a[i] - c[j]) + abs(b[i] - d[j])) == tmp) continue;
            tmp = min((abs(a[i] - c[j]) + abs(b[i] - d[j])), tmp);
            if((abs(a[i] - c[j]) + abs(b[i] - d[j])) == tmp){
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
}
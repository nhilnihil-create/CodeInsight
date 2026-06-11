#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n,k;
    cin >> n >> k;
    ll a[n], b[n];
    REP(i,n){
        cin >> a[i];
        b[i] = max(a[i], 0LL);
    }
    ll suma[n] = {}, sumb[n] = {};
    for(int i = 0; i < n; i++){
        suma[i + 1] = suma[i] + a[i];
        sumb[i + 1] = sumb[i] + b[i];
    }
    ll ans = 0;
    for(int i = 0; i <= n - k; i++){
        ans = max(ans, sumb[i] - sumb[0] + sumb[n] - sumb[i + k]);
        ans = max(ans, sumb[i] - sumb[0] + suma[i + k] - suma[i] + sumb[n] - sumb[i + k]);
    }
    cout << ans << endl;
    return 0;
}
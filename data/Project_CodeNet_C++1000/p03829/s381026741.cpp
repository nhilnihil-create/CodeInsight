#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> x(n);
    rep(i,n) cin >> x.at(i);
    ll ans = 0;
    for(int i=1; i<n; i++){
        ll tmp = x.at(i) - x.at(i-1);
        if(tmp*a > b){
            ans += b;
        }
        else ans += tmp * a;
    }

    cout << ans << endl;
    return 0;
}

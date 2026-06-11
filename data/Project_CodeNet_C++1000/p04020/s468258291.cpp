#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
#include<complex>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n+1);
    a[n] = 0;
    ll cnt = 0;
    ll ans = 0;
    rep(i, n+1) {
        cin >> a[i];
        if ( a[i] == 0 ) {
            ans += cnt / 2;
            cnt = 0;
        }
        else {
            cnt += a[i];
        }
//        cout << cnt << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

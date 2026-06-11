#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    ll I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ll ans = 0;
    ans += O;
    ll i = I%2, j = J%2, l = L%2, s = i+j+l;
    ans += I+J+L-s;
    if(s == 3) ans += 3;
    elif(s == 2 && I>0 && J>0 && L>0) ans += 1;
    cout << ans << endl;
}
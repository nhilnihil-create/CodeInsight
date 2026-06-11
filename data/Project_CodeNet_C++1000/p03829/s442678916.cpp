#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    for(ll i=0;i<n;i++) cin >> x[i];

    ll ans = 0;
    for(ll i=0;i<n-1;i++){
        if( a*(x[i+1]-x[i]) > b) ans += b;
        else ans += a*(x[i+1]-x[i]);
    }

    cout << ans << endl;
    return 0;
}

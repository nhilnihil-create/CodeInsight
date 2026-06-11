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

    ll n; cin >> n;
    ll ans = (to_string(n)).size();

    for(ll a=2;a*a<=n;a++){
        if(n%a != 0) continue;
        ll b = n/a;
        ll cur = max(to_string(a).size(),to_string(b).size());
        ans = min(ans,cur);
    }

    cout << ans << endl;
    return 0;

}

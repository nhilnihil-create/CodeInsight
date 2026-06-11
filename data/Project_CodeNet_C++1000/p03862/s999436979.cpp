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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    ll ans = 0;

    if(a[0] > x){
        ans += a[0] - x;
        a[0] = x;
    }

    for(ll i=1;i<n;i++){
        if(a[i]+a[i-1] > x){
            ans += a[i] + a[i-1] - x;
            a[i] = x - a[i-1];
        }
    }

    cout << ans << endl;
    return 0;
}

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
    vector<ll> a(n+1);
    a[0] = 0;
    for(ll i=1;i<n+1;i++){
        cin >> a[i];
    }

    vector<ll> ans(n+1);
    ans[0] = 0;

    if(n%2 == 0){
        ll idx = n;
        for(ll i=1;i<=n/2;i++){
            ans[i] = a[idx];
            idx -= 2;
        }
        idx = 1;
        for(ll i=n/2+1;i<=n;i++){
            ans[i] = a[idx];
            idx += 2;
        }
    }

    if(n%2 == 1){
        ll idx = n;
        for(ll i=1;i<=n/2+1;i++){
            ans[i] = a[idx];
            idx -= 2;
        }
        idx = 2;
        for(ll i=n/2+2;i<=n;i++){
            ans[i] = a[idx];
            idx += 2;
        }
    }


    for(ll i=1;i<=n;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}


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
    ll n;
    cin >> n;
    map<ll,ll> A;
    for(ll i=0;i<n;i++){
        ll a; cin >> a;
        A[a]++;
    }

    ll ans = 0;
    map<ll,ll>::iterator it;
    for(it=A.begin();it!=A.end();it++){
        if(it->second%2 == 1) ans++;
    }

    cout << ans << endl;
    return 0;
}


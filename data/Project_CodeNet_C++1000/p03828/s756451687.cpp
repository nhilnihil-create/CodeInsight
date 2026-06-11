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
    if(n == 1){cout << 1 << endl; return 0;}
    map<ll,ll> a;

    for(ll cur=2;cur<=n;cur++){
        ll cur2 = cur;
        for(ll i=2;i*i<=cur2;i++){
            int num = 0;
            if(cur2 % i == 0){
                while(cur2 % i == 0){
                    cur2 /= i;
                    a[i]++;
                }
            }
        }
        if(cur2 != 1) a[cur2]++;
    }

    ll ans = 1;
    map<ll,ll>::iterator it;
    for(it=a.begin();it!=a.end();it++){
        ans *= it->second + 1;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}

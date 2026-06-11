#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);

	if(a%b == 0)return(b);

	else return(gcd(b, a%b));
}

int main(){
    int n;
    cin >> n;

    ll l, r;
    l = r = 0;
    rep(i, n){
        ll t, a;
        cin >> t >> a;

        if(t >= l && a >= r){
            l = t, r = a;
        }
        else {
            ll t_m = l / t;
            ll a_m = r / a;
            if(l % t > 0)t_m++; 
            if(r % a > 0)a_m++; 

            ll min_m = min(t_m, a_m);
            ll max_m = max(t_m, a_m);

            if(t * min_m >= l && a * min_m >= r){
                l = t * min_m, r = a * min_m;
            }
            else {
                l = t * max_m, r = a * max_m;
            }
        }
    }
    cout << l + r << endl;
}

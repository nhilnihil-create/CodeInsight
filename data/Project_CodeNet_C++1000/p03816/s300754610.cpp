#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


const ll MOD = 1e9+7;
 
signed main(){
    ll n;
    cin >> n;
    vector<ll> vec;
    rep(i,0,n){
        ll a;
        cin >> a;
        vec.push_back(a);
    }
    
    sort(vec.begin(),vec.end());

    ll roopcnt = 0,memo = 0;
    while(roopcnt < n){
        ll temp_cnt = roopcnt, temp = vec[roopcnt];
        while(temp == vec[roopcnt]){
            roopcnt++;
        }

        if((roopcnt - temp_cnt) % 2) memo++;
    }

    vec.erase(unique(vec.begin(),vec.end()),vec.end());

    if((vec.size() - memo) % 2) cout << vec.size() - 1  << endl;
    else cout << vec.size() << endl;

    return 0;
}

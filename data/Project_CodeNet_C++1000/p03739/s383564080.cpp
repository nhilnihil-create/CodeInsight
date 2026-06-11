#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

vector<vector<ll>> g(100010); 
vector<ll> dist(100010);

int main(){
    ll n;
    cin >> n;

    ll a[n];
    rep(i, n)cin >> a[i];

    //初項を負の数で始めるケース
    ll ans = 0;
    ll sum;
    if(a[0] >= 0){
        sum = -1;
        ans += a[0] + 1;
    }
    else {
        sum = a[0];
    }

    for(ll i = 1; i < n; ++i){
        if((i&1 && sum+a[i] <= 0) || (!(i&1) && sum+a[i] >= 0)){
            ans += llabs(sum+a[i]) + 1;
            sum = -1*(sum/llabs(sum));
        }
        else {
            sum += a[i];
        }
    }

    //初項を正の数で始めるケース
    ll res = 0;
    if(a[0] <= 0){
        sum = 1;
        res += abs(a[0]) + 1;
    }
    else {
        sum = a[0];
    }

    for(ll i = 1; i < n; ++i){
        if((!(i&1) && sum+a[i] <= 0) || (i&1 && sum+a[i] >= 0)){
            res += llabs(sum+a[i]) + 1;
            sum = -1*(sum/llabs(sum));
        }
        else {
            sum += a[i];
        }
    }

    ans = min(ans, res);
    cout << ans << endl;
}
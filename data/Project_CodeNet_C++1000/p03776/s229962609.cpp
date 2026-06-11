#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n,a,b; cin >> n >> a >> b;
    vl v(n);
    rep(i,n) cin >> v[i];
    sort(v.rbegin(), v.rend());
    double value = 0.0;
    rep(i,a){
        value += v[i];
    }
    value = value / (double)a;
    printf("%.8f\n",value);
    ll ans = 0;
    if(v[0] == v[a-1]){
        ll cnt = 0;
        rep(i,n) if(v[0] == v[i]) cnt++;
        REP(i,a,b+1){
            if(v[i-1] != v[0]) break;
            ll t = 1;
            rep(j,i){
                t *= cnt-j;
                t /= j+1;
            }
            ans += t;
        }
    }else{
        ll cnt1 = 0;
        ll cnt2 = 0;
        rep(i,n) if(v[i] == v[a-1]) cnt1++;
        rep(i,n){
            if(v[i] == v[a-1]) break;
            cnt2++;
        }
        cnt2 = a - cnt2;
        ans = 1;
        rep(i,cnt2){
            ans *= cnt1 - i;
            ans /= i+1;
        }
    }
    cout << ans << endl;
}

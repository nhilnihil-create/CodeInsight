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
#define MAX 510000
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n; cin >> n;
    vl a(n);
    vl index(n+1);
    rep(i,n){
        cin >> a[i];
        index[a[i]] = i;
    }
    set<ll> se;
    se.insert(n);
    se.insert(-1);
    ll ans = 0;
    REP(i,1,n+1){
        auto itr = se.lower_bound(index[i]);
        ll right = *itr - index[i];
        itr--;
        ll left = index[i] - *itr;
        ans += i * right * left;
        se.insert(index[i]);
    }
    cout << ans << endl;
}
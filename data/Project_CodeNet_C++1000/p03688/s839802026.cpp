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
    ll n; cin >> n;
    vl a(n);
    map<ll,ll> mp;
    ll mx = 0, mn = INF;
    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    bool flag = true;
    if(mp.size() > 2){
        flag = false;
    }else if(mp.size()==2){
        if(mx - mn >= 2) flag = false;
        else{
            ll y = mp[mx];
            ll x = n - mp[mx];
            if(2 * (mx - x) <= y) flag = true;
            else flag = false;
            if(mx <= x) flag = false;
        }
    }else{
        if(n/a[0] >= 2 || a[0] == n-1) flag = true;
        else flag = false;
    }
    if(flag) puts("Yes");
    else puts("No");
}

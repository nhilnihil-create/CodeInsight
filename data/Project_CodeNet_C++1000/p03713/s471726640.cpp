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
#define MOD 998244353
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
    ll h,w; cin >> h >> w;
    if(h%3==0 || w%3==0) puts("0");
    else{
        ll ans = h*w;
        ll mn = 0;
        ll mid = 0;
        ll mx = h*w;
        rep(i,w){
            mx -= h;
            mn += h/2;
            mid += (h+1)/2;
            ans = min(ans,max({mid-mn,abs(mx-mn),abs(mx-mid)}));
            //cout << ans << endl;
        }
        mn = 0;
        mid = 0;
        mx = h*w;
        rep(i,h){
            mx -= w;
            mn += w/2;
            mid += (w+1)/2;
            ans = min(ans,max({mid-mn,abs(mx-mn),abs(mx-mid)}));
            //cout << ans << endl;
        }
        ans = min({h,w,ans});
        cout << ans << endl;
    }
}

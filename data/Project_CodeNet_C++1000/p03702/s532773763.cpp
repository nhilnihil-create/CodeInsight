#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9+7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
#define INT_MAX 1e9+7

int main(){
    ll n,a,b; cin >> n >> a >> b;
    ll c = a-b;
    vl h(n);
    rep(i,n) cin >> h[i];
    ll ok = 1e10;
    ll ng = -1;
    while(ok-ng>1){
        ll mid = (ok+ng)/2;
        vl hh(n);
        rep(i,n){
            hh[i] = h[i] - b*mid;
        }
        ll cnt = 0;
        rep(i,n){
            if(hh[i]<=0) continue;
            cnt += (hh[i]+c-1)/c;
        }
        if(cnt > mid) ng = mid;
        else ok = mid;
    }
    cout << ok << endl;
}
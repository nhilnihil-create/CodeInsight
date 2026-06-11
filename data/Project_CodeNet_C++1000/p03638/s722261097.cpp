#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
#define MOD (ll)(1e9+7)
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    ll h,w;
    cin >> h >> w;
    ll n;
    cin >> n;
    ll a[n],index = 0;
    ll memo[h][w] = {};
    rep(i,0,n) cin >> a[i];

    rep(i,0,h){
        rep(j,0,w){
            if(i % 2 == 0){
                memo[i][j] = index+1;
            }
            else{
                memo[i][w-j-1] = index+1;
            }

            if(--a[index] <= 0){
                index++;
            }
        }
    }
    rep(i,0,h){
        rep(j,0,w){
            cout << memo[i][j] << ((j == w-1)?"":" ");
        }
        cout << endl;
    }
    return 0;
}
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
    string s,t;
    cin >> s >> t;
    ll cnt = 0;
    rep(i,0,n){
        ll tmp = 0;
        rep(j,0,n){
            if(s[i+j] != t[j]) break;
            tmp++;
        }

        cnt = max(cnt,tmp);
    }

    cout << 2*n - cnt << endl;
    return 0;
}

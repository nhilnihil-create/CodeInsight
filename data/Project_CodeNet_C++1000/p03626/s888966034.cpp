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
    ll n;
    cin >> n;
    string s,t;
    cin >> s >> t;

    ll ans = 1;
    t = "";
    rep(i,0,s.size()){
        if(i < (ll)s.size()-1 && s[i] == s[i+1]){
            t += '2';
            i++;
        }
        else{
            t += '1';
        }
    }

    rep(i,0,t.size()){
        if(i == 0){
            if(t[i] == '2') ans = 6;
            else ans = 3;
        }
        else if(t[i] == t[i-1]){
            if(t[i] == '1') ans *= 2;
            else ans *= 3;
        }
        else{
            if(t[i-1] == '1') ans *= 2;
        }
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
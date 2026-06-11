#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    map<ll,ll> h;
    rep(i,n){
        ll a;
        cin >> a;
        h[a]++;
    }
    vector<pll> ans;
    for(auto x:h){
        ans.push_back(x);
    }
    sort(ans.rbegin(),ans.rend());
    ll m=ans.size();
    ll cnt=0;
    ll s=1;
    vector<ll> b(2);
    rep(i,m){
        if(ans[i].se>=2){
            b[cnt]=ans[i].fi;
            ans[i].se-=2;
            cnt++;
            i--;
        }
        if(cnt==2) break;
    }
    rep(i,2){
        s*=b[i];
    }
    cout << s << endl;
    return 0;
} 
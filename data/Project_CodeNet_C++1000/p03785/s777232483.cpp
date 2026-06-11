#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;


template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;

int main(){
    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    rep(i,n){
        cin >> t[i];
    }
    sort(t.begin(),t.end());
    ll st=t[0];
    ll pos=0;
    ll ans=0;
    while(true){
        if(pos+c-1<=n-1 && t[pos+c-1]<=st+k){
            pos=pos+c;
            ans++;
            if(pos==n) break;
            st=t[pos];
        }
        else{
            auto it=upper_bound(t.begin(),t.end(),st+k)-t.begin();
            ans++;
            if(it==n) break;
            pos=it;
            st=t[pos];
            
        }
    }
    cout << ans << endl;
    return 0;
}
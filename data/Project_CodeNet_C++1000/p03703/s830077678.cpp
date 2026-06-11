#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair

const ll MaxN=3*1e5;

ll bit[MaxN];
void add(ll a, ll w) {
    for (ll x = a; x <= MaxN; x += (x & -x)) bit[x] += w;
}

ll sum(ll a) {
 ll ret = 0;
 for (ll x = a; x > 0; x -= (x & -x)) ret += bit[x];
 return ret;
}

int main(){
    ll N,K;
    cin>>N>>K;
    vec d;
    rep(i,N){
        ll x; cin>>x;
        d.pb(x-K);
    }
    vec r(N+1,0),s(N+1,0);
    rep(i,N) {
        r.at(i+1)=r.at(i)+d.at(i);
        s.at(i+1)=r.at(i+1);
    }
    sort(s.begin(),s.end());
    vec p(N+1);

    rep(i,N+1){
        p.at(i)=lower_bound(s.begin(),s.end(),r.at(i))-s.begin();
    }


    ll ans=0;
    rep(i,N+1){
        ans+=sum(p.at(i)+10);
        add(p.at(i)+10,1);
    }
    cout<<ans<<endl;


}
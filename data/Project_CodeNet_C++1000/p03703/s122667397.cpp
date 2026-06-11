#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9;
const ll mod=998244353;
vector<ll>bit(1000010);
ll n;
ll sum(ll i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i=i&(i-1);
    }
    return s;
}
void add(ll i,ll a){
    while(i<=n){
        bit[i]+=a;
        i+=i&-i;
    }
}
signed main(){
    ll n_,k;cin>>n_>>k;
    vector<ll>a(n_+1);
    set<ll>st;
    ll ans=0;
    rep(i,n_){
        cin>>a[i+1];
        a[i+1]+=a[i];
        st.insert(a[i+1]-i*k-k);
    }
    st.insert(0);
    n=st.size();
    ll cnt=1;
    map<ll,ll>m;
    for(auto e:st){
        m[e]=cnt;
        cnt++;
    }
    add(m[0],1);
    rep(i,n_){
        ll d=m[a[i+1]-i*k-k];
        ans+=sum(d);
        //cout<<i<<' '<<sum(d)<<endl;
        add(d,1);
    }
    cout<<ans<<endl;
}
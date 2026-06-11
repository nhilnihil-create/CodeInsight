#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    ll a;cin>>a;
    map<ll,ll>m;
    map<ll,ll>m2;
    vector<ll>c(0);
    ll sum=a;
    m[a]=1;
    m2[a]=0;
    c.pb(a);
    rep(i,n-1){
        ll b;cin>>b;
        sum+=b;
        if(m.find(b)==m.end()){
            m[b]=1;
            m2[b]=i+1;
            c.pb(b);
        }else{
            m[b]++;
        }
    }
    sort(all(c));
    reverse(all(c));
    vector<ll>ans(n);
    ll cnt=0;
    ll cnt2=0;
    c.pb(0);
    m2[0]=inf;
    rep(i,c.size()-1){
        cnt+=m[c[i]];
        ll s=m2[c[i]];
        ll t=m2[c[i+1]];
        ans[s]+=(c[i]-c[i+1])*cnt;
        m2[c[i+1]]=min(s,t);
        cnt2+=(c[i]-c[i+1])*cnt;
    }
    rep(i,n){
        cout<<ans[i]<<endl;
    }
}
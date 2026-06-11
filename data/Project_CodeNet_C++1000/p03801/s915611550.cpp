#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

const ll mod=1e9+7;
const ll inf=1ll<<60;

/*---------------------*/

ll n,a,ans[100009];
vector<pair<ll,ll>>p;

int main(){
    cin>>n;
    rep(i,n){
        cin>>a;
        p.push_back({a,i});
    }
    sort(p.begin(),p.end(),greater<pair<ll,ll>>());
    ll mn=1e9;
    rep(i,n){
        chmin(mn,p[i].second);
        ans[mn]+=(i==n-1?p[i].first:p[i].first-p[i+1].first)*(i+1);
    }
    rep(i,n)cout<<ans[i]<<endl;
}
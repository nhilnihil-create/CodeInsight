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
const int inf=1e9+7;
const int mod=998244353;
int main(){
    ll h,w;cin>>w>>h;
    priority_queue<ll,vector<ll>,greater<ll> >p;
    priority_queue<ll,vector<ll>,greater<ll> >q;
    rep(i,w){
        ll a;cin>>a;
        p.push(a);
    }
    rep(i,h){
        ll a;cin>>a;
        q.push(a);
    }
    ll ans=0;
    ll cntw=0;
    ll cnth=0;
    ll cnt=0;
    h++;w++;
    while(cnt<h+w-2){
        ll a=inf,b=inf;
        if(!p.empty())a=p.top();
        if(!q.empty())b=q.top();
        if(q.empty()||a<b){
            ans+=(h-cnth)*a;
            p.pop();
            cnt++;
            cntw++;
            //cout<<a<<' '<<h-cnth<<endl;
        }else if(p.empty()||a>=b){
            ans+=(w-cntw)*b;
            q.pop();
            cnt++;
            cnth++;
            //cout<<b<<' '<<w-cntw<<endl;
        }
    }
    cout<<ans<<endl;
}
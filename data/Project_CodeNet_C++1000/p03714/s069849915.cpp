#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
  ll n;cin >> n;
  vl v(3*n);rep(i,3*n)cin >> v[i];
  vl left(n+1,0),right(n+1,0);
  rep(i,n)left[0]+=v[i];
  rep(i,n)right[0]+=v[3*n-1-i];
  priority_queue<ll,vl,greater<ll>> que;
  rep(i,n)que.push(v[i]);
  rep(i,n){
    ll d=v[n+i];
    ll tmp=left[i];
    if(d>que.top()){
      tmp-=que.top();que.pop();
      que.push(d);
      tmp+=d;
    }
    left[i+1]=tmp;
  }
  priority_queue<ll,vl,less<ll>> q;
  rev(all(v));
  rep(i,n)q.push(v[i]);
  rep(i,n){
    ll d=v[n+i];
    ll tmp=right[i];
    if(d<q.top()){
      tmp-=q.top();q.pop();
      q.push(d);
      tmp+=d;
    }
    right[i+1]=tmp;
  }
  rev(all(right));
  ll ans=-INF;
  rep(i,n+1)chmax(ans,left[i]-right[i]);
  //rep(i,n+1)cout << left[i] <<" " << right[i] <<endl;
  cout << ans <<endl;
}
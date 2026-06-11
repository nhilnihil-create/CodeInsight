#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n;
  cin>>n;
  vll t(n),a(n);
  rep(i,n) cin>>t[i];
  rep(i,n) cin>>a[i];
  vll tt(0),aa(0);
  tt.pb(1);
  aa.pb(1);
  ll ma=a[0];
  ll mt=t[0];
  for(int i=1;i<n;i++){
    mt=max(t[i],mt);
    if(t[i]!=t[i-1]){
      tt.pb(1);
    }
    else{
      tt.pb(t[i]);
    }
  }
  for(int i=n-1;i>0;i--){
    ma=max(ma,a[i]);
    if(a[i]!=a[i-1]){
      aa.pb(1);
    }
    else{
      aa.pb(a[i]);
    }
  }
  if(ma!=mt){
    COUT(0);
    return 0;
  }
  ll ans=1;
  ll k=1;
  rep(i,n){
    ans*=min(aa[n-i-1],tt[i]);
    ans%=MOD;
    if(a[i]==ma&&t[i]==mt)k=0;
    if(aa[n-i-1]==1&&a[i]>t[i]){
      COUT(0);
      return 0;
    }
    if(tt[i]==1&&t[i]>a[i]){
      COUT(0);
      return 0;
    }
  }
  if(k){
    COUT(0);
    return 0;
  }
  COUT(ans);
}

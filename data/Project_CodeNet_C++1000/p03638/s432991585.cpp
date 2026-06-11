#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main() {
  ll H;
  ll W;
  cin >>H>>W;
  
  ll N;
  cin >>N;
  vl a(N);
  rep(i,N) {
cin >>a.at(i);
  }

  ll data[H*W];
  rep(i,H*W) {
data[i]=0;
  }
  
  ll x=0;
  rep(i,N) {
    rep(j,a.at(i)) {
      data[x]=i+1;
      x++;
    }
  }
  ll y=0;
  bool ans=true;
  rep(i,H) {
    rep(j,W) {
      if(i%2==0) {
        cout<<data[i*W+j]<<" ";
      }
      
      else if(i%2!=0) {
        cout<<data[(i+1)*W-1-j]<<" ";
       
      }
   
    }
    cout<<endl;
  }
  
  
  
cout<<endl;  
  
}
        
      
      
     
      
      
    
    

  
 
      
      
  
  
  
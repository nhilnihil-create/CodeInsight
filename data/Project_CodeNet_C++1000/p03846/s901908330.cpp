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
long long fac(ll a) {
 long long ans=1;
 while(a>=1){
 ans*=2;
 ans%=1000000007;
   a--;
     ;
    }
    return ans;
     }


int main() {
ll N;
  cin >>N;
  vl a(N);
  rep(i,N) {
cin >>a.at(i);
  }
  sort(all(a));
  
  
  
  if(N%2!=0) {
    vl vec(N);
    vec.at(0)=0;
    repl(i,1,(N-1)/2+1) {
      vec.at(2*i-1)=2*i;
      vec.at(2*i)=2*i;
    }
    bool ans=true;
    rep(i,N) {
      if(a.at(i)!=vec.at(i)) {
ans=false;
        break;
      }
    }
    
    if(!ans) {
cout<<0<<endl;
    }
    else {
      cout<<fac(N/2)<<endl;
                }
  }
  
  
  
  
  else if(N%2==0) {
    vl veec(N);
   
    repl(i,0,(N)/2) {
      veec.at(2*i)=2*i+1;
      veec.at(2*i+1)=2*i+1;
    }
    bool ans=true;
    rep(i,N) {
      if(a.at(i)!=veec.at(i)) {
ans=false;
        break;
      }
    }
    
    if(!ans) {
cout<<0<<endl;
      
      
    }
    else {
      cout<<fac(N/2)<<endl;
                }
  }
  
  
  
  
}
      
 
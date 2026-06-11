#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N;
  cin>>N;
  ll a[N];
  rep(i,N) cin>>a[i];
  
  vl judge(10,false);
  
  ll red=0;
  
  for(int i=0;i<N;i++){
    
    if(a[i]/400>=8) red++;
    else{
      judge[a[i]/400]=true;
    }
    
  }
  
  ll ma=0,mi=0;
  
  for(int i=0;i<10;i++){
    if(judge[i]) mi++;
  }
  ma=mi+red;
  if(mi==0) mi=1;
  
  cout<<mi<<" "<<ma<<endl;
}

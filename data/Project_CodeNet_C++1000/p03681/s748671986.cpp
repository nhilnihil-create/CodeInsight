#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

ll kaijo(ll x){
  if(x==1) return x=1; 
  return x%inf*kaijo(x-1)%inf;
}



int main() {
  ll n,m;
  cin>>n>>m;
  ///
  ll ans=0;
  if(n==m){
    ans+=kaijo(n)%inf*kaijo(m)%inf;
    ans=ans*2%inf;
  }
  if(abs(n-m)==1){
   ans+=kaijo(n)%inf*kaijo(m)%inf; 
  }

  
  
  cout<<ans%inf<<endl;  
}
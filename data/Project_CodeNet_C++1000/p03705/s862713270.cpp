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

int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  ////////////
  ll ans=0;
  if(a==b) {
    cout<<1<<endl;
    return 0 ;
  }
  if(b<a){
    cout<<ans<<endl;
   return 0 ; 
  }
  if(n==1) {
    cout<<0<<endl; 
    return 0;
  }
  ans++;
  ans+=b*(n-1)+a-(a*(n-1)+b);
  cout<<ans<<endl;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
const ll mod2=1e9+9 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
  ll h,w;
  cin>>h>>w;
  vector<pli> v;
  rep(i,h){
    ll x;cin>>x;
    v.push_back({x,0});
    }
  rep(i,w){
    ll x;cin>>x;
    v.push_back({x,1});
    }
  h++;w++;
  sort(v.begin(),v.end());
  ll ans=0;
  for(auto x:v){
    if(x.second){
      ans+=h*x.first;
      w--;
      }
    else {
      ans+=w*x.first;
      h--;
      }
    }
  cout<<ans<<endl;  
  return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1000003 ;

ll comb[100][100];

int main(){
  for(int i=0;i<61;i++){
    comb[i][0]=1;
    comb[i][i]=1;
  }
  for(int i=2;i<=61;i++){
    for(int j=1;j<i;j++){
      comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
    }
  }
  int n,a,b;
  cin >> n >> a >> b;
  ll v[n];
  rep(i,n){
    cin >> v[i];
  }
  sort(v,v+n,greater<ll>());
  map<ll,ll> mp;
  vector<pair<long double,ll>> res;
  rep(i,n)mp[v[i]]++;
  for(int i=a;i<=b;i++){
    long double ave=0;
    ll cnt=0;
    ll com=1;
    for(int j=0;j<i;j++){
      ave+=v[j];
      if(v[j]==v[i-1])cnt++;
    }
    ave/=(long double)i;
    com=comb[mp[v[i-1]]][cnt];
    res.push_back({ave,com});
  }
  sort(res.begin(),res.end());
  reverse(res.begin(),res.end());
  ll ans=0;
  rep(i,res.size()){
    if(res[i].first==res[0].first)ans+=res[i].second;
  }
  cout << setprecision(10) << res[0].first << endl;
  cout << ans << endl;
return 0;}
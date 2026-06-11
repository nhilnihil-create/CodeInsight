#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main(){
  string S;
  cin>>S;
  int N=S.size();

  vector<ll> alp(26,0);
  rep(i,N) alp[S[i]-'a']++;

  ll ans=0;
  rep(i,26){
    ans+=(alp[i])*(N-alp[i]);
  }
  cout<<ans/2+1<<endl;


  return 0;
}

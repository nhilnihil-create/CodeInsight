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
  int N;
  ll A,B,C,D;
  cin>>N>>A>>B>>C>>D;

  if(A>B) swap(A,B);
  bool ok=false;
  for(ll i=0;i<=N-1;i++){
    ll rest=B-(A+C*i-C*(N-1-i));
    if(rest>=0){
      if(rest<=(D-C)*i) ok=true;
    }else{
      if(-rest<=(D-C)*(N-1-i)) ok=true;
    }
  }

  if(ok) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}

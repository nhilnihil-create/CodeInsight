#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  ll a,b; cin>>a>>b;
  if (a<=0&&b>=0) {
    cout<<"Zero"<<endl;
    return 0;
  }
  if (a>0){
    cout<<"Positive"<<endl;
    return 0;
  } else {
    if ((b-a+(ll)1e12)%2==1) {
      cout<<"Positive"<<endl;
      return 0;
    } else {
      cout<<"Negative"<<endl;
      return 0;
    }
  }
}

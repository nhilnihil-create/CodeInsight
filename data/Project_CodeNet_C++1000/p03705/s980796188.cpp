#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  ll n,a,b; cin>>n>>a>>b;
  if (a==b) {
    cout<<1<<endl; return 0;
  }
  if (a>b) {
    cout<<0<<endl;
    return 0;
  }
  if (n==1) {
    cout<<0<<endl;
    return 0;
  }
  ll sm1 = a + b * (n-1);
  ll sm2 = a * (n-1) + b;
  cout << sm1 - sm2 + 1 << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <functional>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;

int main() {
  string s; cin>>s;
  bool N=false,W=false,S=false,E=false;
  for(char ch:s) {
    N=max(N,ch=='N');
    W=max(W,ch=='W');
    S=max(S,ch=='S');
    E=max(E,ch=='E');
  }
  if((N==S)&&(W==E)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
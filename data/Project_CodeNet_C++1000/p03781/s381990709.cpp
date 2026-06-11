#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std; using ll=long long; const int INF=1e2; using P=pair<int,int>;

int main() {
  ll x; cin>>x;
  ll an;
  for(an=1;an*(an+1)/2<x;an++);
  cout<<an<<endl;
}

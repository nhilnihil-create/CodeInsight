#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  ll x,y; cin>>x>>y;
  ll an=2e9+1;
  for(ll i=-1;i<=1;i+=2) {
    for(ll j=-1;j<=1;j+=2) {
      if (x * i <= y * j)
        an=min(an,(i==-1)+(j==-1)+abs(y*j-x*i));
    }
  }
  cout<<an<<endl;
}
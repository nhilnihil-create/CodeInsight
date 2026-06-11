#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n; cin>>n;
  vector<pair<ll,ll>> ab(n);
  
  for(int i=0;i<n;i++){
    ll a,b; cin>>a >>b;
    ab.push_back(make_pair(a,b));
  }
  
  sort(ab.rbegin(),ab.rend());
  
  cout<<ab[0].first+ab[0].second<<endl;
  return 0;
}
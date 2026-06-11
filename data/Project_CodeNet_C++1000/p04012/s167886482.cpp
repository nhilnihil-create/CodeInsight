#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  map<char,ll> S;
  string w;
  cin>>w;
  for(ll i=0;i<w.size();i++) {
S[w[i]]++;
  }
  for(auto x:S) {
if(x.second%2!=0) {
cout<<"No"<<endl;
return 0;
}
  }
  
  
  cout<<"Yes"<<endl;
}
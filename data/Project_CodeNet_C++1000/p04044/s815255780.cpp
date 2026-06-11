#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,L;
  cin>>N>>L;
  vector<string> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  sort(all(vec));
  for(ll i=0;i<N;i++) {
cout<<vec[i];
  }
  cout<<endl;
}

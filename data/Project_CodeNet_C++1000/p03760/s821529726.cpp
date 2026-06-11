#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S,T;
  cin>>S>>T;
  for(ll i=0;i<T.size();i++) {
cout<<S[i]<<T[i];
  }
  if(S.size()!=T.size()) {
cout<<S.back();
  }
  
  cout<<endl;
}
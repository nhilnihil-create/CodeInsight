#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  set<char> A;
  for(ll i=0;i<S.size();i++) {
if(A.count(S[i])) {
cout<<"no"<<endl;
  return 0;
}
   A.insert(S[i]);
   }
   
   cout<<"yes"<<endl;
   }

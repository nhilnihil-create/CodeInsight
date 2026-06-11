#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S,T,U;
  cin>>S>>T>>U;
  if(S.back()==T[0]&&T.back()==U[0]) {
cout<<"YES"<<endl;
  }
  else {
cout<<"NO"<<endl;
  }
}
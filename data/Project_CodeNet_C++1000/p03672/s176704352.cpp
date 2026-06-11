#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int ans=0;
  string halfS;
  for(int i=1;i<S.size()/2;i++){
    halfS=S.substr(0,i)+S.substr(0,i);
    if(halfS==S.substr(0,i*2))
      ans=i*2;
  }
  cout<<ans<<endl;
}

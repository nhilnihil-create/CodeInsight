#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  string W;
  
  for(ll i=0;i<S.size();i++) {
    if(S[i]=='1') {
W.push_back('1');
    }
else if(S[i]=='0') {
W.push_back('0');
}
    else if(W.size()>0&&S[i]=='B') {
W.pop_back();
    }
  }
  
  
 
  cout<<W<<endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {

string S;
  cin>>S;
  ll max=0;
  ll count=0;
  for(ll i=0;i<S.size();i++) {
if(count==0&&S[i]=='A') {
count++;
  continue;
}
    if(count>0) {
count++;
    }
    
    if(S[i]=='Z') {
max=count;
    }
  }
  
  cout<<max<<endl;
}
  
  

  
  
  
  
  

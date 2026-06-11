#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll H,W;
  cin>>H>>W;
  for(ll i=0;i<W+2;i++) {
cout<<'#';
  }
  cout<<endl;
  for(ll i=0;i<H;i++) {
    string S;
    cin>>S;
    S='#'+S+'#';
    cout<<S<<endl;
  }
   for(ll i=0;i<W+2;i++) {
cout<<'#';
  }
  cout<<endl;
}
  
  
  
  
  

  
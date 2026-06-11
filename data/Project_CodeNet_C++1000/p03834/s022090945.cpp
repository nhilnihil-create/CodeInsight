#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  for(ll i=0;i<19;i++) {
    if(i==5||i==13) {
cout<<" ";
    }
    else {
cout<<S[i];
    }
  }
  
  cout<<endl;
}

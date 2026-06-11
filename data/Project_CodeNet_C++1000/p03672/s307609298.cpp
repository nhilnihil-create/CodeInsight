#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.length()/2;
  int ans=0;
  
  for(int i=1;i<n;i++){
    if(s.substr(0,i)==s.substr(i,i)){
      ans=i*2;
    }
  }
  cout<<ans<<endl;
}

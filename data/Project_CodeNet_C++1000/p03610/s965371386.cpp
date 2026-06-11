#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  int l=S.size();
  string ans;
  for(int i=0;i<l;i+=2) ans=ans+S.at(i);
  cout<<ans<<endl;
}

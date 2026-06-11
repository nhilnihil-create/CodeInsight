#include <bits/stdc++.h>
using namespace std;

int main(){
  string A="CODEFESTIVAL2016";
  string B;
  cin>>B;
  int ans=0;
  for(int i=0;i<A.length();i++){
    if(A.at(i)!=B.at(i))ans++;
  }
  cout<<ans<<endl;
  return 0;
}

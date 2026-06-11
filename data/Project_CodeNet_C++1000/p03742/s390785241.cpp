#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int x,y;cin>>x>>y;
  string ans;
  if(abs(x-y)<=1)ans="Brown";
  else ans="Alice";
  cout<<ans<<endl;
}
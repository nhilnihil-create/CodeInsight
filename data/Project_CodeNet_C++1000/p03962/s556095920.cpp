#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
  cin>>a>>b>>c;
  set<int>S;
  S.insert(a);
  S.insert(b);
  S.insert(c);
  int ans=S.size();
  cout<<ans<<endl;
  
  
   return 0;
}
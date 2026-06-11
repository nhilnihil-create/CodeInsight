#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
string s,t;
  cin>>N>>s>>t;
  int ans=2*N;
  for(int i=0;i<N;i++){
    bool x=true;
  for(int j=0;j<N-i;j++){
  if(t.at(j)!=s.at(i+j)){
   x=false; break;
  }
   }if(x){
  s.erase(i);
    ans=i+N; break;
  }
  
  }cout<<ans<<endl;
   return 0;
}
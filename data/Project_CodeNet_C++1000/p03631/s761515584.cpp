#include<bits/stdc++.h>
using namespace std;
int main(){
string N;
  cin>>N;
  int n=N.size();
  bool ans=true;
  for(int i=0;i<n/2;i++){
  if(N.at(i)!=N.at(n-1-i)){
    ans=false; break;
  }
  
  }if(ans)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
   return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  int64_t x;
  cin>>x;
  vector<int64_t>A(N+1);
  A.at(0)=0;
  for(int i=1;i<=N;i++)
    cin>>A.at(i);
  int64_t ans=0;
  for(int i=0;i<N;i++){
  if(x<A.at(i)+A.at(i+1)){
  int64_t y=A.at(i)+A.at(i+1)-x;
    A.at(i+1)-=y;
    ans+=y;
  
  }
   
  
  }cout<<ans<<endl;
   return 0;
}
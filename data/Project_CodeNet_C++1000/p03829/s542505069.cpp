#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t N,A,B;
  cin>>N>>A>>B;
  vector<int64_t>X(N);
  for(int64_t i=0;i<N;i++){
  int64_t x;
    cin>>x;
    X.at(i)=x;
  
  }int64_t ans=0;
  for(int64_t i=0;i<N-1;i++){
  int64_t cost=A*(X.at(i+1)-X.at(i));
    ans+=min(cost,B);
  
  }cout<<ans<<endl;
   return 0;
}
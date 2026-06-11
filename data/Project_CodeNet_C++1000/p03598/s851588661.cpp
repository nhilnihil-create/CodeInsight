#include <bits/stdc++.h>
using namespace std;
int lenght(int x){
  if(x<0){ 
  return -x;
  }
  else{
  return x;
  }
}
int main(){
  int N,K;
  cin>>N>>K;
  vector<int> x(N);
  for(int i=0;i<N;i++){
    cin>>x.at(i);
  }
  int ans=0;
  for(int i=0;i<N;i++){
    ans+=min(lenght(K-x.at(i)),lenght(x.at(i)))*2;
  }
  cout<<ans<<endl;
}
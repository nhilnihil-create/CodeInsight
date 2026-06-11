#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin>>N>>K;
  vector<int> vec(N, 0);
  for(int i=0; i<N; i++){
    cin>>vec.at(i);
  }
  int ans=0;
  for(int i=0; i<N; i++){
    if(vec.at(i)<K-vec.at(i)){
      ans+=2*vec.at(i);
    }
    else{
      ans+=2*(K-vec.at(i));
    }

  }
  cout<<ans<<endl;
}
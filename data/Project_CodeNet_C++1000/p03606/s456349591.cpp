#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  
  int ans=0;
    
  for(int i=0;i<N;i++){
    vector<int>vec(2);
    cin>>vec[1]>>vec[2];
    
    ans+=vec[2]+1-vec[1];
  }
  
  cout<<ans<<endl;
}
    
    
    
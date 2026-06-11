#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    if(vec[vec[i]-1]==i+1){
      ans++;
    }
  }
  
  cout<<ans/2<<endl;
}
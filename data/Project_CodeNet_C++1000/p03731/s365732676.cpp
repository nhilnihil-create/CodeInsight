#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int N,T;
  cin>>N>>T; 
  vector<int>a(N);
  for(int i=0;i<N;++i){
    cin>>a.at(i);
  }
  long ans=0;

  for(int i=0;i<N-1;i++){
    if(a.at(i)+T<a.at(i+1)){
       ans+=T;
    }
    else{
      ans+=a.at(i+1)-a.at(i);
    }
  }
  
    cout<<ans+T<<endl; 
}


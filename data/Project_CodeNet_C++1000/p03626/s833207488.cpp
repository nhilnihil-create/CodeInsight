#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int mod=1000000007;
  int N;
  cin>>N;
  string s,t;
  cin>>s>>t;
  if(N==1){
    cout<<3<<endl;
  }
  else if(N==2){
    cout<<6<<endl;
  }
  else{
  vector<long> dp(N);
  dp.at(0)=3;
  dp.at(1)=6;
  for (int i = 2; i < N; i++) {
    if(s.at(i)==t.at(i)){
      if(s.at(i-1)==t.at(i-1)){
        dp.at(i)=2*dp.at(i-1)%mod;
      }
      else{
        dp.at(i)=dp.at(i-1);
      }
    }
    else{
      if(s.at(i-2)==t.at(i-2)){
        dp.at(i)=2*dp.at(i-2)%mod;
      }
      else{
        dp.at(i)=3*dp.at(i-2)%mod;
      }
    }
  }
    cout<<dp.at(N-1)<<endl;
  }

}


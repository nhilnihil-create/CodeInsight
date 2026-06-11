#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  long N;
  cin>>N; 
  int mod=1000000007;
  vector<bool>a(N-1);
  for (int i = 0; i < N-1; i++) {
    a.at(i)=true;
    for (int j = 2; j <= sqrt(i+2); j++) {
      if((i+2)%j==0){
        a.at(i)=false;
        break;
      }  
    }
  }
  long ans=1;
  for (int i = 0; i < N-1; i++) {
    if(a.at(i)){
      int yo=N/(i+2);
      int di=yo;
      while(di>1){
        di/=(i+2);
        yo+=di;
      }
      ans=ans*(yo+1)%mod;
    }
  }
  
      cout<<ans<<endl;
 
}
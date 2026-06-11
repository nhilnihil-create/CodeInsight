#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  long N;
  cin>>N; 
  vector<int>a(N);
  for (int i = 0; i < N; i++) {
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  
  int ans=0;
  int b=a.at(0);
  for (int i = 1; i < N; i++) {
    
    if(a.at(i)==b){
      ans++;
    }
    else{
      b=a.at(i);
    }
  }
    if(ans%2==0){
      cout<<N-ans<<endl;
    }else{
      cout<<N-ans-1<<endl;
    }
 
  
 
}








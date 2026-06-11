#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int K,S;
  cin>>K>>S;
  
  
  int ans=0;
  
  for(int i=0;i<K+1;i++){
    for(int j=0;j<K+1;j++){
      if(i+j<=S&&i+j+K>=S){
        ans++;
      }
    }
  }
  
  
  cout<<ans<<endl;
}
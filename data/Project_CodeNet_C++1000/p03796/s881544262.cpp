#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  int ans=1;
  
  long long x=pow(10,9)+7;
  
  
  for(int i=1;i<=N;i++){
    ans=(ans*(i%x))%x;
  }
  
  cout<<ans<<endl;
}
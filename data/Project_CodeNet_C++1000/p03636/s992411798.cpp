#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  
  int ans=0;
  
  for(int i=1;i<S.size()-1;i++){
    ans++;
  }
  
  cout<<S[0]<<ans<<S[S.size()-1]<<endl;
}
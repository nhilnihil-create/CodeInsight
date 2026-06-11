#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  for(int i=S.size()-2;i>0;i-=2){
    bool bo=false;
    for(int j=0;j<i/2;j++)
      if(S[j]!=S[j+i/2]){
        bo=true;
        break;
      }
    if(bo)
      continue;
    cout<<i<<endl;
    return 0;
  }
}
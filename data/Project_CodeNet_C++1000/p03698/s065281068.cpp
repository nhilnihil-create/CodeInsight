#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  int N=S.size();
  bool b=true;
  for (int i=0; i<N; i++){
    for (int j=i+1; j<N; j++){
      if(S[i]==S[j]){
        b=false;
        break;
      }
    }
  }
  if(b)puts("yes");
  else puts("no");
}

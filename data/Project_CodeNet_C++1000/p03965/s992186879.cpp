#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool g=true;
  int ans=0;
  if(S[0]=='p') ans=-1;
  for(int i=1; i<S.size(); i++){
    if(g){
      if(S[i]=='g') ans++;
      g=false;
    }else{
      if(S[i]=='p') ans--;
      g=true;
    }
  }
  cout << ans << endl;
  return 0;
}
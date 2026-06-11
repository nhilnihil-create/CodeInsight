#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int a=S.size(),z=0;
  for(int i=0;i<S.size();i++){
    if(S[i]=='A')
      a=min(a,i);
    else if(S[i]=='Z')
      z=i;
  }
  cout<<z-a+1<<endl;
}
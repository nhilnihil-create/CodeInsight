#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int ss=S.size();
  if(S[0]==S[ss-1]){
    if(ss&1)
      cout<<"Second"<<endl;
    else
      cout<<"First"<<endl;
  }else{
    if(ss&1)
      cout<<"First"<<endl;
    else
      cout<<"Second"<<endl;
  }
}
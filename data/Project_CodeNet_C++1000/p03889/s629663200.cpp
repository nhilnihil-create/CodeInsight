#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;cin>>S;
  string H=S;
  reverse(S.begin(),S.end());
  for(int X=0;X<S.size();X++){
    if(S[X]=='p'){
      S[X]='q';
    }
    else if(S[X]=='q'){
      S[X]='p';
    }
    if(S[X]=='b'){
      S[X]='d';
    }
    else if(S[X]=='d'){
      S[X]='b';
    }
  }
  if(H==S){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}

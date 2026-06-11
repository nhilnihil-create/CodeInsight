#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  char ch=S.at(0);
  int j=0;
  for(char &c:S)
    if(c!=ch){
      j++;
      ch=c;
    }
  cout<<j<<endl;
}
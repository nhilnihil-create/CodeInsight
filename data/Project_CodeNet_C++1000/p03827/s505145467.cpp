#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>N>>S;
  int i=0,j=0;
  for(char &c:S)
    if(c=='I'){
      i++;
      j=max(j,i);
    }
    else
      i--;
  cout<<j<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> S(3);
  for(string &s:S)
    cin>>s;
  vector<queue<int>> A(3);
  for(int i=0;i<3;i++)
    for(char &c:S.at(i))
      A.at(i).push(c);
  int i=0;
  while(true){
    if(A.at(i).empty()){
      cout<<(char)('A'+i)<<endl;
      return 0;
    }
    char c=A.at(i).front();
    A.at(i).pop();
    i=(int)(c-'a');
  }
}
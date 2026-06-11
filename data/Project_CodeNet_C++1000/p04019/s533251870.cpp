#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  map<char,int> A;
  for(char c:S)
    A[c]++;
  if(A.count('N')==A.count('S') && A.count('E')==A.count('W'))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
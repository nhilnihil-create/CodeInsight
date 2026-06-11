#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  unordered_set<int> A;
  for(char c:S)
    A.insert(c);
  for(char c='a';(int)c<='z';c=(char)((int)c+1))
    if(!A.count(c)){
      cout<<c<<endl;
      return 0;
    }
  cout<<"None"<<endl;
}
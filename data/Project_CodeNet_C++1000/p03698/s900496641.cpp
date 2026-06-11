#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  unordered_set<char> A;
  for(char &c:S){
    if(A.count(c)){
      cout<<"no"<<endl;
      return 0;
    }
    A.insert(c);
  }
  cout<<"yes"<<endl;
}
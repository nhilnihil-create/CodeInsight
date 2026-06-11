#include<bits/stdc++.h>
using namespace std;
int main(){
  string z;
  cin>>z;
  int x=z.length(),i;
  vector<int> q(26);
  for(i=0;i<x;i++) q.at(z.at(i)-'a')=1;
  for(i=0;i<26;i++){
    if(q.at(i)==0){
      cout<<(char)('a'+i)<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}
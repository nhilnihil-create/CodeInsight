#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s;
  t=s;
  reverse(s.begin(),s.end());
  for(char &ch:s){
    if(ch=='b')ch='d';
    else if(ch=='d')ch='b';
    else if(ch=='p')ch='q';
    else if(ch=='q')ch='p';
  }
  cout<<(s==t?"Yes":"No")<<endl;
  return 0;
}

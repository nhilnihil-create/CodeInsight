#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a;
  b=a;
  reverse(b.begin(),b.end());
  for(int i=0;i<b.size();i++){
    if(b.at(i)=='p')
      b.at(i)='q';
    else if(b.at(i)=='q')
      b.at(i)='p';
    else if(b.at(i)=='b')
      b.at(i)='d';
    else if(b.at(i)=='d')
      b.at(i)='b';
    }
  if(a==b)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  }

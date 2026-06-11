#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  string a,b;
  cin>>a>>b;
  if(a==b) cout<<"EQUAL";
  else if(a.size()<b.size()) cout<<"LESS";
  else if(a.size()>b.size()) cout<<"GREATER";
  else if(a<b) cout<<"LESS";
  else cout<<"GREATER";
}
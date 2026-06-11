#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin>>a>>b;
  if(a.size()>b.size())cout<<"GREATER"<<endl;
  if(a.size()<b.size())cout<<"LESS"<<endl;
  if(a.size()==b.size()){
    if(a>b)cout<<"GREATER"<<endl;
    else if(a<b)cout<<"LESS"<<endl;
    else if(a==b)cout<<"EQUAL"<<endl;
  }
  
}

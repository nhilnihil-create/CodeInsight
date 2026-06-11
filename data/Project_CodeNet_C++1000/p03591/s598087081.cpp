#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int a=s.size();
  if(a<4){
    cout<<"No"<<endl;
    return 0;
  }
  
  if(s.at(0)=='Y'&&s.at(1)=='A'&&s.at(2)=='K'&&s.at(3)=='I'){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
  return 0;
}
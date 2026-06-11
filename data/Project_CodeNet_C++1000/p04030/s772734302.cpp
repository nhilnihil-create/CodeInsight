#include <bits/stdc++.h>
using namespace std;


int main() {


  string s;
  cin>>s;

  string o;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='0')
      o.push_back(s.at(i));
    else if(s.at(i)=='1')
      o.push_back(s.at(i));
    else if(s.at(i)=='B' && o.empty()!=true)
      o.pop_back();
  }

  cout<<o<<endl;

  return 0;
}


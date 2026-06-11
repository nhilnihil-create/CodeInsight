#include <bits/stdc++.h>
using namespace std;

int main()
{
  string t="CODEFESTIVAL2016";
  string s;
  cin>>s;
  
  int cnt=0;
  for(int i=0;i<t.size();i++){
    if(t.at(i)!=s.at(i))
      cnt++;
  }
  
  cout<<cnt<<endl;
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string AC="CODEFESTIVAL2016";
  string s;
  
  int result=0;
  
  cin>>s;
  
  for(int i=0;i<s.size();i++){
    if(s.at(i)!=AC.at(i))result++;
  }
  cout<<result<<endl;
  
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int c=0;
  for(int i=1;i<s.size();i++)
    if(s.at(i-1)!=s.at(i))
      c++;
  cout<<c<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int l,i;
  cin>>s;
  l=s.length();
  for(i=0;i<l;i+=2) cout<<s.at(i);
  cout<<endl;
}
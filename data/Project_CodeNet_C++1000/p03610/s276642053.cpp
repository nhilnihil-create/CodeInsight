#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s;
  cin>>s;
  int size=s.size();
  for(int i=0;i<size;i+=2){
    cout<<s[i];
  }
  cout<<'\n';
  return 0;
}
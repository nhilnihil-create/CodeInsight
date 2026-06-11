#include<iostream>
using namespace std;
int main(){
  string s,t="CODEFESTIVAL2016";
  cin>>s;
  int a=0;
  for(int i=0;i<16;i++)a+=s[i]!=t[i];
  cout<<a<<endl;
}
  
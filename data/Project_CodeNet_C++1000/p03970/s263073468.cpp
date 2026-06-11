#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  string t="CODEFESTIVAL2016";
  int count=0;
  for(int i=0;i<16;i++){
    if(s[i]!=t[i]){
      count++;
    }
  }
  cout<<count;
}
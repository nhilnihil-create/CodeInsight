#include <bits/stdc++.h>
using namespace std;

int main(){
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  cout<<(char)((int)(s1.at(0))+('A'-'a'));
  cout<<(char)((int)(s2.at(0))+('A'-'a'));
  cout<<(char)((int)(s3.at(0))+('A'-'a'));
  cout<<endl;
}
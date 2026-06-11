#include<iostream>
using namespace std;

int main(){
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  char x = s1[0]-0x20;
  char y = s2[0]-0x20;
  char z = s3[0]-0x20;
  string s = {x,y,z};
  cout<<s<<endl;
  return 0;
}

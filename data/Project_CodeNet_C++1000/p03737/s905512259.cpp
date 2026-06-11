#include<iostream>
using namespace std;
int main()
{
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  string str;
  str+=toupper(s1[0]);
    str+=toupper(s2[0]);
  str+=toupper(s3[0]);
  cout<<str;
}
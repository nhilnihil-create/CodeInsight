#include<iostream>
#include<string>
using namespace std;
string s;
char f(char a)
{
  if(a=='b')return 'd';
  if(a=='d')return 'b';
  if(a=='p')return 'q';
  if(a=='q')return 'p';
}
int main()
{
  cin>>s;
  for(int i=0;i<s.size();i++)
    if(s[i]!=f(s[s.size()-i-1])){cout<<"No";return 0;}
  cout<<"Yes";
  return 0;
}

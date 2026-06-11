#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int rock=0;
  int paper=0;
  string str="";
  int count=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='g'){
    if(paper<rock)
    {
      str+='p';
     // count++;
      paper++;
    }
    else
    {
      str+='g';
     // count--;
      rock++;
    }
    }
    else
    {
        if(paper<rock)
    {
      str+='p';
          //count++;
          paper++;
    }
    else
    {
      str+='g';
     // count--;
      rock++;
    }
    }

  }
  //cout<<str;
  for(int i=0;i<str.length();i++)
  {
      if(s[i]=='p' && str[i]=='g')
       count--;
      else if(s[i]=='g' && str[i]=='p')
        count++;
      else
      {

      }

  }
  cout<<count;
  return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   string s="CODEFESTIVAL2016";
  string s1;
  cin>>s1;
  int i,cnt=0;
  for(i=0;i<s1.length();++i)
  {
    if(s1[i]!=s[i])
       cnt++;
  }
  
  printf("%d",cnt);
   
   
}
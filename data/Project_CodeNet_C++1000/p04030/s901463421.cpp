#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  stack<char> q;
  for(int i=0;i<s.length();i++)
  {
     if(s[i]=='0' || s[i]=='1')
       q.push(s[i]);
     else if(!q.empty() && s[i]=='B')
       q.pop();
  }string k;
   while (!q.empty()) 
    { 
       k+=q.top();
     q.pop();
    } 
  reverse(k.begin(),k.end());
  cout<<k;
  return 0;
    
}
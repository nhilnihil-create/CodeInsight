#include <bits/stdc++.h>
using namespace std;

bool cmp(string &s, string &t)
{
  if (s.size()!=t.size())
    return s.size()>t.size();
  return s>t;
}

int main()
{
  string s,t; cin>>s>>t;
  if (s==t){
    cout<<"EQUAL"<<endl;
    return 0;
  }
  if (cmp(s,t)) cout<<"GREATER"<<endl;
  else cout<<"LESS"<<endl;
  return 0;
}

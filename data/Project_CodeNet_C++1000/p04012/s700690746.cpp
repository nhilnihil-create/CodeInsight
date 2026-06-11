#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  string s;
  cin>>s;
  map<char,int>m;
  for(int i=0;i<s.size();i++)
  {
      m[s[i]]++;
  }
  map<char,int>::iterator it;
  int f=0;
  for(it=m.begin();it!=m.end();it++)
  {
      int x=it->second;
      if(x%2!=0)
      {
           f=1;
          cout<<"No\n";break;
      }
  }
  if(f==0)
    cout<<"Yes\n";
}

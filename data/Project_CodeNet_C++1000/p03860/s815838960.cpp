#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,k=0;
    string s;
    getline(cin,s);
    cout<<s[0];
    for(i=6;i<s.size();i++)
    {
      if(s[i]>=65&&s[i]<=90)
      cout<<s[i];
    }
  cout<<endl;
  return 0;
}

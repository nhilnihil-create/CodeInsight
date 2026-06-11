
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

   ll a,b;
  cin>>a>>b;
  vector<string>v;
  string h;
  for(int i=1;i<=b+2;i++)
  {
      h+="#";
  }
  //cout<<h<<endl;
  for(int i=1;i<=a;i++)
  {
      string s;
      cin>>s;
      v.push_back(s);
  }
  cout<<h<<endl;
  for(int i=0;i<a;i++)
  {
      cout<<"#"<<v[i]<<"#"<<endl;
  }
  cout<<h<<endl;



}









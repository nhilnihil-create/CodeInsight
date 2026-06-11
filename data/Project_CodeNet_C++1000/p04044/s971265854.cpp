#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,l;
  cin>>n>>l;
  vector<string> a;
  for(int i=0;i<n;i++)
  {
    string s;
	cin>>s;a.push_back(s);
  }
  sort(a.begin(),a.end());
  string s;
  for(auto x:a)
  {
    s+=x;
  }
  cout<<s;
  return 0;
}
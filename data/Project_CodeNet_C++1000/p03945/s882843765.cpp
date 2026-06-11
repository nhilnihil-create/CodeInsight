#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin>>s;
  int ctr=0;
  for (int i = 0; i < s.size()-1; ++i)
  {
  	if(s[i] != s[i+1])
    ctr++;
  }

  cout<<ctr;
  return 0;
}
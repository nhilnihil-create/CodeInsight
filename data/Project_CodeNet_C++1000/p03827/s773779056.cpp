#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a=0,b,m=0,n,i;
  cin>>n;
  string s;
  cin>>s;
  for(i=0;i<s.size();i++)
  {
     if(s[i]=='I') a++;
     else a--;
     m=max(a,m);

  }
  std::cout << m << '\n';
return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i=s;i<n;i++)

int main()
{
  int a,c;
  char b;
  cin >> a >> b >> c;
  
  int ans;
  if(b=='+')
    ans=a+c;
  else
    ans=a-c;
  
  cout << ans <<endl;
}
  
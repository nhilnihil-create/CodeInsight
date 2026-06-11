#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
char a,b;int ans;
int main()
{
  cin>>a>>b;
  if(a=='D')ans++;
  if(b=='D')ans++;
  if(ans%2==0)cout<<'H'<<endl;
  else cout<<'D'<<endl;
  return 0;
}

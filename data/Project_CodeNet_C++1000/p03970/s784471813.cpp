#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;
string st;
long long ans;
char ch[20]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
int main()
{
 cin>>st;
 for(int i=0;i<16;i++)
 {
  if(st[i]!=ch[i]) ans++;
 }
 cout<<ans;
 return 0;
}

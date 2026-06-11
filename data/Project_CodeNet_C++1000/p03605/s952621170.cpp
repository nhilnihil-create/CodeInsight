#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
  int a,ans=0;
  cin>>a;
  ans+=(a%10==9);
  ans+=(a/10==9);
  if(ans>=1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}

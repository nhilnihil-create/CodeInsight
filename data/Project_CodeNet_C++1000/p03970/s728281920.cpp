#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
  string a,b="CODEFESTIVAL2016";
  cin>>a;
  for(int i=0; i<16; i++)
  {
    if(a[i]!=b[i])n++;
  }
  cout<<n;
  return 0;
}
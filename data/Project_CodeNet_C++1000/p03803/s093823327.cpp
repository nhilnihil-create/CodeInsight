#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  if(a==1 && b==1)puts("Draw");
  else if(a==1)puts("Alice");
  else if(b==1)puts("Bob");
  else
  {
    if(a>b)puts("Alice");
    else if(a==b)puts("Draw");
    else puts("Bob");
  }
}
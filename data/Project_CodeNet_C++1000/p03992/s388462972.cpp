#include<bits/stdc++.h>
#define f() for(int i=0;i<n;i++)
using namespace std;
string c;
char t;
int main()
{
  cin>>c;
  c[12]=c[11];
  c[11]=c[10];
  c[10]=c[9];
  c[9]=c[8];
  c[8]=c[7];
  c[7]=c[6];
  c[6]=c[5];
  c[5]=c[4];
  c[4]=' ';
  for(int i=0; i<13; i++)cout<<c[i];
cout<<endl;
  return 0;
}
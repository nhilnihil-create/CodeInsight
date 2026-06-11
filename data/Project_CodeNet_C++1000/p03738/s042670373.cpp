#include<bits/stdc++.h>
using namespace std;

int main()
{
  string a,b;cin>>a>>b;
  if(a.size()>b.size()){printf("GREATER\n");return 0;}
  else if(a.size()<b.size()){printf("LESS\n");return 0;}
  for(int i=0;i<a.size();i++)
  {
    if(a[i]>b[i]){printf("GREATER\n");return 0;}
    else if(a[i]<b[i]){printf("LESS\n");return 0;}
  }
  printf("EQUAL\n");
}
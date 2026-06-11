
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5];
int main()
{
  int c = 1;
  for(int i=0;i<3;i++){cin>>a[i];}
  for(int i=1;i<3;i++){
        if(a[i] != a[i-1]) c++;
  }
  if(c==3 && a[0]==a[2]) cout<<2;
  else
  cout<<c;
}

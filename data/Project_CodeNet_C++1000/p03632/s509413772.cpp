#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,x,y;
  cin>>a>>b>>x>>y;
  int aa=max(a,x);
  int bb=min(b,y);
  if(bb<aa)cout<<0<<endl;
  else cout<<bb-aa<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c,d,area1,area2;
  cin>>a>>b>>c>>d;
  area1=a*b;
  area2=c*d;
  if(area1>area2)
    cout<<area1<<endl;
  else if(area1<area2)
    cout<<area2<<endl;
  else if(area1==area2)
    cout<<area1<<endl;
  return 0;
  
}
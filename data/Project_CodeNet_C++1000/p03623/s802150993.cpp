#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
  
  int x,a,b;
  
  cin>>x>>a>>b;
  
  a=abs(x-a);
  b=abs(x-b);
  if(b>a)
    cout<<"A\n";
  else
    cout<<"B\n";
  
  return 0;
}
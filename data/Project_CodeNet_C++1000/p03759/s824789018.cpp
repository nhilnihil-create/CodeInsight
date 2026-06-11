#include<iostream> 
using namespace std; 
  
int main ()
{
  int a,b,c,p1,p2;
  cin>>a>>b>>c;
  p1=b-a;
  p2=c-b;
  if (p1==p2)
  {
      cout<<"YES\n";
  }
  else
  {
      cout<<"NO\n";
  }
    return 0;
}
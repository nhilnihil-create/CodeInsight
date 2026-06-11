#include<iostream> 
using namespace std; 
  
int main ()
{
  int a,b,sum;
  cin>>a>>b;
  sum=a+b;
  if (sum>=24)
  {
      sum=sum-24;
      cout<<sum<<"\n";
  }
  else  
  {
      cout<<sum<<"\n";
  }
    return 0;
}
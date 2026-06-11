#include<iostream>
#define ll long long
using namespace std;
int main()
{
  ll a,b,c,a1,b1,c1;
  int result=0;
  cin>>a>>b>>c;
  if(a%2!=0 || b%2!=0 || c%2!=0)
  {
    cout<<0;
  }
  else if(a==b && b==c)
  {
    cout<<-1;
  }
  else
  {
  	while(a%2==0 && b%2==0 && c%2==0)
  	{
      a1=a;
      b1=b;
      c1=c;
      a=b1/2+c1/2;
      b=a1/2+c1/2;
      c=a1/2+b1/2;
      result++;
    }
    cout<<result;
  }
  return 0;
}
    

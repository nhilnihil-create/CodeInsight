#include<iostream> 
#include<string>
using namespace std; 
 
int main ()
{
  int a,b,c;
  cin>>a>>b>>c;
  if ((c<=b)&&(c>=a))
  {
      cout<<"Yes\n";
  }
  else
  {
      cout<<"No\n";
  }
    return 0;
}
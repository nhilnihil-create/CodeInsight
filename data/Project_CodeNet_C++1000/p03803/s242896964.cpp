#include <iostream>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  if(a==b)
  {
  cout<<"Draw\n";}
  else if((a<b&&a!=1)||b==1)
  {
    cout<<"Bob\n";
  }
  else 
  {
    cout<<"Alice\n";
  }
}

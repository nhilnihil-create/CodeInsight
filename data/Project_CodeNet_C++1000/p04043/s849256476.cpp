//🤦‍♀️🤦‍♀️😒
#include<iostream>
using namespace std;
int main()
{
  int a[3];
  for(int i=0;i<3;i++)
  {
    cin>>a[i];
  }int f=0,s=0;
  for(int i=0;i<3;i++)
  {
    if(a[i]==5)
      ++f;
    else if(a[i]==7)
      ++s;
    else 
      break;
  }
  if(f>=2 && s>=1)
  {
    cout<<"YES";
  }
  else
    cout<<"NO";
}

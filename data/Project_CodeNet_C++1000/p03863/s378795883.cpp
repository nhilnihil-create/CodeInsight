#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a;
  cin>>a;
  int k=a.length();
  if(a[0]==a[k-1])
  {
    if(k%2==0)
	{
      cout<<"First"<<endl;
      return 0;
    }
    else
	{
      cout<<"Second"<<endl;
      return 0;
    }
  }
  else
  {
    if(k%2==0)
	{
      cout<<"Second"<<endl;
      return 0;
    }
    else
	{
      cout<<"First"<<endl;
      return 0;
    }
  }
  return 0;
}
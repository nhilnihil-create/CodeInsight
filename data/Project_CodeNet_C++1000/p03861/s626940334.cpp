#include <iostream>

using namespace std;

int main()
{
  long long a,b,x,coun=0;
  cin>>a>>b>>x;
  coun=b/x-a/x;
  if(a%x==0)
  {
      coun++;
  }
  cout<<coun<<endl;
}

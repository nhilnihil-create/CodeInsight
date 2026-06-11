#include<iostream>
using namespace std;
int main()
{
  int a,b,c,c5=0,c7=0;
  cin>>a>>b>>c;
  if(a==5)
    c5++;
  else if(a==7)
    c7++;
  if(b==5)
    c5++;
  else if(b==7)
    c7++;
  if(c==5)
    c5++;
  else if(c==7)
    c7++;
  if(c5==2&&c7==1)
    cout<<"YES";
  else cout<<"NO";
}

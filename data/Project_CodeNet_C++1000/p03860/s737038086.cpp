#include<iostream>
using namespace std;
int main()
{
  string s;
  getline(cin,s);
  int l=s.size();
  int i;
  char a;
  for(i=0;i<l;i++)
  {
    if(s[i]==' ')
    {
      i++;
      a=s[i];
     break;
    }
  }
  cout<<"A"<<a<<"C";
  return 0;
}
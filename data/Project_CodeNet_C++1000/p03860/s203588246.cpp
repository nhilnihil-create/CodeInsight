#include<iostream>
using namespace std;
int main()
{
  string a;
  getline(cin,a);
  int length=a.length();
  for(int i=0;i<length;i++)
  {
        if(i==0)
      {
          cout<<a[i];
      }
      else if(a[i]==' ')
         {
           cout<<a[i+1];
         }
  }








    return 0;
}

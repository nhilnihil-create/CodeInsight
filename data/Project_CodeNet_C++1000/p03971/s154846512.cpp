#include<iostream>
using namespace std;
int main()
{
  int n,A,B;
  cin >> n >> A >> B;
  char a[n];
  cin>>a;
  int c1=0,c2=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]=='c')
    {
      cout<<"No"<<endl;
      continue;
    }
    if(a[i]=='a')
    {
      if(c1< A+B)
      {
        c1++;
        cout<<"Yes"<<endl;
        continue;
      }
      else
        cout<<"No"<<endl;
    }
    if(a[i]=='b')
    {
      //c2++;
      if(c1< A+B && c2<B)
      {
        c1++;c2++;
        cout<<"Yes"<<endl;
        continue;
      }
      else
        cout<<"No"<<endl;
    }
  }
  return 0;
}
      

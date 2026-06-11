#include<iostream>
using namespace std;
int main()
{  int n,s;
  cin>>n>>s;
 long int cnt=0;
 for(int i=0;i<=n;i++)
 {  int t1=s-i;
  if(t1>2*n||t1<0)
      continue;
   for(int j=0;j<=n;j++)
    {  int t2=t1-j;
       if(t2>n||t2<0)
           continue;
     cnt++;
    }
 }
 cout<<cnt;
}
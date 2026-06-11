#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3],i;
  for(i=0;i<3;i++)
  {
   cin>>a[i]; 
  }
  sort(a,a+3);
  
  if((a[0]==5)&&(a[1]==5)&&(a[2]==7))
  {
    
        cout<<"YES";
  }
  
  else
  {
    cout<<"NO";
  }
  return 0;
}

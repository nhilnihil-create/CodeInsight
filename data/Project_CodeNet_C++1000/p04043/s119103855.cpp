#include <iostream>
#include<algorithm>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);
     cin.tie(NULL);
      cout.tie(NULL);
  
  int a[3];
  for(int i=0;i<3;i++)
  {
    cin>>a[i];
  }
 sort(a,a+3);
 if(a[0]==5&&a[1]==5&&a[2]==7)
   cout<<"YES";
 else
   cout<<"NO";
   
  return 0;}

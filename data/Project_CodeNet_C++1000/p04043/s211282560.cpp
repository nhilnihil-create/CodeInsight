#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<math.h>
#include<cstring>
using namespace std;
void lets_play()

{
    int a[10],i;
   int c1=0,c2=0;
  for(i=0;i<3;i++)
  {
      cin>>a[i];
  }

    if( a[0]==5&&a[1]==5&&a[2]==7|| a[0]==5&&a[1]==7&&a[2]==5|| a[0]==7&&a[1]==5&&a[2]==5)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }

int main()
{
        lets_play();

}

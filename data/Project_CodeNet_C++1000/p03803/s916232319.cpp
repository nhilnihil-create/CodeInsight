#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
 int x,y;
 cin>>x>>y;
if(x==y)
    cout<<"Draw"<<endl;
  else  if(x==1) cout<<"Alice"<<endl;
  else  if(y==1) cout<<"Bob"<<endl;
  else {
      if(x>y) cout<<"Alice"<<endl;
      else cout<<"Bob"<<endl;

      }

}
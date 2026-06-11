#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
int x,y,z,n=1;
cin>>x>>y>>z;
if(x!=y&&x!=z&&z!=y)
cout<<"3"<<endl;
else if(x==y&&x==z&&z==y)
cout<<"1"<<endl;
else
cout<<"2"<<endl;

 return 0;
}

#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <limits>
using namespace std;

int main()
{
int a,b,c; cin>>a>>b>>c;
if(a!=b&&a!=c&&b!=c)
    cout<<"3";
else if(a==b&&b!=c)
    cout<<"2";
else if(b==c&&c!=a)
    cout<<"2";
else if(c==a&&b!=a)
    cout<<"2";
else
    cout<<"1";
}
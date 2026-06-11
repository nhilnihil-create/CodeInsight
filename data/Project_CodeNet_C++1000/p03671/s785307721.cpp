#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <limits>
using namespace std;

int main()
{
int a,b,c; cin>>a>>b>>c;

if(a+b<a+c&&a+b<b+c)
   cout<<a+b;
else if(b+c<a+c)
    cout<<b+c;
else
   cout<<a+c;
}
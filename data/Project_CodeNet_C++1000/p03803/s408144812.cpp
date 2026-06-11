#include <iostream>
#include <string>
using namespace std;

int main()
{
int a,b;
cin>>a>>b;
if(a==1&&b!=1)
       cout<<"Alice";
if(b==1&&a!=1)
       cout<<"Bob";
if(a>b&&a!=1&&b!=1)
       cout<<"Alice";
else if(b>a&&a!=1&&b!=1)
       cout<<"Bob";
else if(a==b)
       cout<<"Draw";

    return 0;
}

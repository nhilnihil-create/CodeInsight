#include <iostream>;
#include <stdlib.h>;
using namespace std;
int main ()
{
    int w,a,b;
    cin>>w>>a>>b;
    if (abs(a-b)<=w){cout<<0<<endl;}
    else if (abs(b-(a+w))<abs((b+w)-a)){cout<<abs(b-(a+w));}
    else{cout<<abs(b+w-a);}
    cout<<endl;
    return 0;
}
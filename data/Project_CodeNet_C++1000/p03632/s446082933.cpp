#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    int a,b,c,d,s,e;
    cin>>a>>b>>c>>d;
    if(a<=c)
        s=c;
    else
        s=a;

    if(b<=d)
        e=b;
    else
        e=d;

    if((e-s)> 0)
        cout<<e-s;
    else
        cout<<0;
    return 0;
}

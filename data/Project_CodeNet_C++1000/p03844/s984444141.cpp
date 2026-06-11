#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    char c;
    cin>>a>>c>>b;
    if(((a&&b)>=1)&&((a&&b)<=pow(10,9)))
    {
        if(c=='+')
            cout<<a+b;
        else if(c=='-')
            cout<<a-b;
    }
    return 0;
}

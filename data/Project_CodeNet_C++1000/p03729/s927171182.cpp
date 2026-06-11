#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char a[20],b[20],c[20];
    int x,y;
    cin>>a>>b>>c;
    x=strlen(a);
    y=strlen(b);
    if(a[x-1]==b[0])
    {
        if(b[y-1]==c[0])
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}

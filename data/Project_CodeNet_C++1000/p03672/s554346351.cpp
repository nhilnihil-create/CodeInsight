#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
//#include <iomanip>
//#include <ctype.h>

using namespace std;

int main()
{
    int n,flag=1,i;
    char str[200];
    cin>>str;
    n=strlen(str);
    if(n%2)
        n--;
    else
        n-=2;
    while(flag)
    {
        flag=0;
        for(i=0;i<n/2;i++)
        {
            if(str[i]!=str[(n/2)+i])
            {
                n=n-2;
                flag=1;
                continue;
            }
        }
    }
    cout<<n;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int now=0;
    for(int i=1;i<=x;i++)
    {
        now+=i;
        if(now>=x)
        {
            cout<<i;
            break;
        }


    }
}
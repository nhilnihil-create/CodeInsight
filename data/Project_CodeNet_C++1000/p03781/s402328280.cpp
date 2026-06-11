#include <iostream>

using namespace std;

int main()
{
    int X,j=0;
    cin>>X;
    for(int i=1;i>0;i++)
    {
        j+=i;
        if(j>=X)
        {cout<<i;
         break;
        }
    }
    return 0;
}

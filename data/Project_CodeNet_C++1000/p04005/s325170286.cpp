#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

unsigned long long a[3];
unsigned long long ans[3];
bool oushu = false;
int main()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        cin>>a[i];
        if((a[i] % 2) == 0) oushu = true;    
    }
    if(oushu)
    {
        cout<<0<<"\n";
        return 0 ;
    }
    ans[0] = a[0] * a[1];
    ans[1] = a[1] * a[2];
    ans[2] = a[0] * a[2];
    sort(ans,ans+3);
    cout<<ans[0]<<"\n";
    return 0;
}
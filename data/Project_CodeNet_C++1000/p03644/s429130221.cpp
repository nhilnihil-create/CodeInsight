///Boot camp for Beginners
///Easy 100
///Problem-11
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    int ans=01;
    cin>>n;

    while(ans*2<=n)
    {
        ans=ans*2;
    }
   cout<<ans<<endl;

    return 0;
}

//In the name of Allah
#include <iostream>

using namespace std;
long long int n,m;
int main()
{
    cin>>n>>m;
    if(m>n*2)
    {


    n*=2;
    m+=n;
    cout<<m/4;
    return 0;
    }
    cout<<m/2;

    return 0;
}

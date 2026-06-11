#include <bits/stdc++.h>
using namespace std;
//*******************
// Mahmoud Magdy    *
//*******************
#define ll long long
#define endl "\n"

void fast()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
inline int D()
{
    int m ;
    cin>>m;
    return m ;
}
inline ll lD()
{
    ll m ;
    cin>>m;
    return m ;
}
inline double dD()
{
    double m ;
    cin>>m;
    return m ;
}
int main()
{
      int x=D();
    int sum = 0;
    for(int i=1;i<=x;i++)
    {
        sum+=i;
        if(sum>=x)
        {
            cout<<i<<endl;;
            return 0;
        }
    }
}

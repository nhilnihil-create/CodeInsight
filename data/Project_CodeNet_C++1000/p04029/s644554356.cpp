/*
** author:mahmoud magdy
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

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
    double m;
    cin>>m;
    return m;
}
void fast()
{
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}
const int N=1e2+5;

int main()
{
   ll n=D();
   cout<<(n*(n+1)/2)<<endl;
}

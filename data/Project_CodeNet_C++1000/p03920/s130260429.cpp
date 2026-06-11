#include <cstdio>
#include <iostream>
#define MOD 1000000007
#define INT long long
using namespace std;
int n, p, d[10001], v;
int main()
{
    for(int i = 1 ; i <= 10000 ; i++ )
        d[i] = d[i-1] + i;
    cin>>n;
    for(p = 0 ; d[p] < n ; p++ );
    v = d[p]-n;
    for(int i = 1 ; i <= p ; i++ )
        if( i != v ) cout<<i<<endl;
    return 0;
}
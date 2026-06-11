#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    set<ll>* a = new set<ll>[n+1];
    for(int i=0;i<m;i++)
    {
        ll temp1 , temp2;
        cin>>temp1>>temp2;
        ll mini = min( temp2 , temp1 );
        ll maxi = max( temp2 , temp1);
        a[mini ].insert( maxi);
    }
    bool found = false;
    auto it = a[1].begin() ;
    for( ;it!= a[1].end( ) ;it++)
    {
        if(  a[ *it  ].find(n) != a[*it].end()  )
        {
            found = true;
            break;
        }
    }
    if( found) cout<<"POSSIBLE";
        else cout<<"IMPOSSIBLE";
}
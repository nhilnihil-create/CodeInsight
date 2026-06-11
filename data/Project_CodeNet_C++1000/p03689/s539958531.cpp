#include<iostream>
#include <bits/stdc++.h>
//1000000000000223
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, x, y;
ll a[600][600], sum;
int main()
{
    IO
    cin>>n>>m>>x>>y;
    ll p=n/x;
    ll z=501;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            a[i][j]= (i%x==0 && j%y==0) ? -z*(x*y-1)-1 : z ;
            sum+=a[i][j];
        }
    if(sum<=0)
        return cout<<"No",0;
    cout<<"Yes\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k,x,y;
    cin>>n>>k>>x>>y;
    if(k>=n)
        cout<<n*x;
    else
        cout<<k*x+(n-k)*y;
    return 0;
}
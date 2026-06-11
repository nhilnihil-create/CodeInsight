#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    if(k>=n)
    {
        k=n;
    }
    ll ans=(x*k)+((n-k)*y);
    cout<<ans;
    return 0;
}






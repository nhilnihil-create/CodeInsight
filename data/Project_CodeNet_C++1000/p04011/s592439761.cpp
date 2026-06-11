#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin.sync();

    int n;
    cin>>n;
    int k;
    cin>>k;
    int x;
    cin>>x;
    int y;
    cin>>y;
    int ans =0;
    if(k<n)
    {
        ans = k*x + y*(n-k);
    }
    else if(k>=n)
    {
        ans = x*n;
    }
    cout<<ans;

    return 0;
}
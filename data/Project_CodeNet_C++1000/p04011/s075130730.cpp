#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,x,y,ans=0;
    cin>>n>>k>>x>>y;

    ans=min(n,k)*x;

    if(n>k){
       ans+=((n-k)*y);
    }

    cout<<ans<<"\n";

    return 0;
}

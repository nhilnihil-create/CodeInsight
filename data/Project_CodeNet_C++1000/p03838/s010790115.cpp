#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x,y;cin>>x>>y;

    int ans=abs(abs(x)-abs(y));

    if(abs(x)>abs(y))ans+=(x>0?1:0)+(y>0?1:0);
    else if(abs(x)<abs(y))ans+=(x<0?1:0)+(y<0?1:0);
    else ans++;

    cout<<ans<<"\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int w,a,b;
    cin>>w>>a>>b;
    int s=a<b?a:b;
    int l=a>b?a:b;

    int ans=l-(s+w);

    if(ans<0) cout<<0;
    else cout<<ans;
}

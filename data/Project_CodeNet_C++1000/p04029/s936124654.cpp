#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long int n,ans=0;
    cin>>n;

    for(int i=1;i<=n;i++){
        ans+=i;
    }

    cout<<ans<<"\n";

    return 0;
}

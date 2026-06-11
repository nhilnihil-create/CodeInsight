/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx=1e5+5;
int ara[mx];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,n,ans=0;
    cin>>n;
    for (i=1;i<=n;i++) cin>>ara[i];
    for (i=1;i<=n;i++) if (i==ara[i]) {
        if (i!=n) {swap(ara[i],ara[i+1]); ans++;}
        else {swap(ara[i],ara[i-1]); ans++;}
    }
    cout<<ans<<endl;
    return 0;
}

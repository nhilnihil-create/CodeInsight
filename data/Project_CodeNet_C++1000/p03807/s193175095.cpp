#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353


int main(void)
{
    fastio;

    int n,i,p,c=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> p;
        if(p%2)c++;
    }
    if(c%2)cout << "NO\n";
    else cout << "YES\n";

    return 0;
}

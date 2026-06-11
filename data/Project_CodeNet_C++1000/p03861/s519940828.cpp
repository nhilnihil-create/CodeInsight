#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    LL a, b, x, ans=0;
    cin>>a>>b>>x;
    ans = (b/x) - (a/x);
    if(a%x==0) ans++;
    cout<<ans<<endl;

    return 0;
}

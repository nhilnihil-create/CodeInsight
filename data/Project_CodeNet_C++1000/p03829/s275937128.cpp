#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100005];
ll ans, b, c, n;
int main() 
{
    cin >> n >> b >> c;
    for(ll i = 1; i <= n; i++)
        cin >> a[i]; 
    for(ll i = 1; i < n; i++)
        ans += min(b * (a[i + 1] - a[i]), c); 
    cout<<ans<<endl;
    return 0; 
}
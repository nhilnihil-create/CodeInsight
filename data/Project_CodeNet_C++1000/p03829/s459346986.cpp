#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, a, b; cin >> n >> a >> b;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    ll sum = 0;
    for(int i=0; i<n-1; i++)
        sum += min((arr[i+1]-arr[i])*a, b);

    cout << sum;
    return 0;
}

#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    ll ans = k;
    printf("%lld\n", (ll)(ans*pow(k-1, n-1)));
    return 0;
}

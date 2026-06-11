#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 2e5 + 5;
ll a[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        //freopen("VLJUM.INP", "r", stdin);
        //freopen("VLJUM.OUT", "w", stdout);
        ll n, x;
        cin >> n >> x;
        cout << 3 * (n - __gcd(n, x));
}


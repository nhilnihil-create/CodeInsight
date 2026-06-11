#include <bits/stdc++.h>
#define MAXN 330
#define pii pair<int, int>
#define pll pair<long long, pair<long long, long long>>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x < n and y >= 0 and y < n)
using namespace std;
const int mod = 1e9 + 7;
const ll oo = 1e17 + 7;


int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    ll n, ans;
    cin >> n;

    if (n <= 6) ans = 1;
    else if(n <= 11) ans = 2;
    else {
        ans = ((n)/11)*2;
        n%11 <= 6? ans++: ans+=2;
        if (n%11 == 0) ans--;
    }

    cout << ans << endl;
    return 0;
}
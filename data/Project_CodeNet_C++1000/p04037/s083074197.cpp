#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int n, a[N];

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    int l = 1;
    while(l + 1 <= n && a[l + 1] >= l + 1) l += 1;

    int r = 0;
    while(l + r <= n && a[l + r] >= l) r += 1;

    l = a[l] - l + 1;
    cout << (r % 2 == 0 || l % 2 == 0 ? "First" : "Second") << "\n";
}


#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e6 + 5;

int n;
int a[Nmax];

bool bad(int l, int c) { return a[l] <= c; }

int main()
{
 //   freopen("input", "r", stdin);
    cin.sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    cin >> n;
    for(i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);

    for(i=n; i; --i)
        if(bad(i, n-i)) break;
    ++i;

    /// vreau sa aflu (i, n-i)

    for(j=i-1; j; --j)
        if(bad(j, n-i)) break;

    int ans1 = (j-i) % 2;
    int ans2 = (a[i] - (n-i)) % 2;

    if(ans1 && ans2) cout << "Second\n";
        else cout << "First\n";

    return 0;
}

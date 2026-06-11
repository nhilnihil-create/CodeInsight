#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> II;
#define X first
#define Y second

const int N = 1e5 + 10;
const int oo = 1e9 + 10;

int n;
II a[N];
ll res[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].X;
        a[i].Y = i;
    }
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    ll cur = oo, pos = n + 1;
    for (int l = 1; l <= n; l++) {
        int r = l;
        res[pos] += (cur - a[l].X) * (ll) (l - 1);
        cur = a[l].X;
        while (a[l].X == a[r].X && r <= n)
            pos = min(a[r++].Y, pos);
        l = r - 1;
    }
    res[1] += cur * (ll)n;
    for (int i = 1; i <= n; i++)
        cout << res[i] << endl;
}

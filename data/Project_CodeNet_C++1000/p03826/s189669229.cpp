#include <bits/stdc++.h>
#define MAXN 2550
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x < n and y >= 0 and y < n)
using namespace std;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << max(a*b, c*d) << endl;
    return 0;
}
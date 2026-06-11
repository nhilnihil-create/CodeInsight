#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const long long MAXN = 1e5 + 21, inf = 1e18 + 21, LG = 20;

long long n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<long long> p(n);

    for(auto &y: p) {
        cin >> y;
        y--;
    }

    vector <long long> q(n);

    for(int i = 0; i < n; i++)
        q[p[i]] = i;

    for(long long i = 0; i < n; i++)
        cout << 30000 * i + 1 << ' ';
    cout << '\n';

    for(long long i = 0; i < n; i++)
        cout << 30000 * (n - 1 - i) + q[i] + 1 << ' ';
    cout << '\n';
    return 0;
}

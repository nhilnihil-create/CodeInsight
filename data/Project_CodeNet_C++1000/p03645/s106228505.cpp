#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    bool start[n], end[n], boat = false;
    for (long long i = 0; i < n; i++)
    {
        start[i] = false;
        end[i] = false;
    }
    for (long long i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (a == 1) start[b - 1] = true;
        if (b == n) end[a - 1] = true;
    }
    for (long long i = 1; i < n; i++)
    {
        if (start[i] == true && end[i] == true)
        {
            boat = true;
            break;
        }
    }
    if (boat == true) cout << "POSSIBLE";
    else cout << "IMPOSSIBLE";
}
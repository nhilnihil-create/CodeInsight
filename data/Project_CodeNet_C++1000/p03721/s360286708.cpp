#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ull n, k;
    cin >> n >> k;

    ull hist[100001] = {0};
    for (int i = 0; i < n; i ++) {
        ull a, b;
        cin >> a >> b;
        hist[a] += b;
    }

    for (int i = 1; i < 100001; i ++) {
        if (hist[i] >= k) {
            cout << i;
            break;
        }
        k -= hist[i];
    }

    return 0;
}
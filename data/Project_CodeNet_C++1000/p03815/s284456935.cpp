#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 60, mod = 1e9 + 7;

LL x;

int main()
{
    cin >> x;
    if(x % 11 == 0) cout << x / 11 * 2 << endl;
    else
    {
        LL res = x / 11 * 2;
        x %= 11;
        if(x <= 6) res += 1;
        else res += 2;
        cout << res << endl;
    }
    return 0;
}

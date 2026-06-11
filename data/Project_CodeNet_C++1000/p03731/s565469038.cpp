#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 200010;
const double eps = 1e-6;

int n, t;
int a[N];
int res;

int main()
{
    cin >> n >> t;

    int l = -1, r = -1;
    while(n--)
    {
        int st;
        cin >> st;
        if(st > r)
        {
            res += r - l;
            l = st, r = st + t;
        }
        else r = max(r, st + t);
    }

    res += r - l;

    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 60, mod = 1e9 + 7;

LL n, m;

bool check(LL x)
{
    LL tn = n, tm = m;
	if(tn < x) tm -= 2 * (x - tn);
	return tm >= 2 * x;
}

int main()
{
    cin >> n >> m;

    LL l = 0, r = 1e12;
    while(l < r)
    {
        LL mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;
    return 0;
}

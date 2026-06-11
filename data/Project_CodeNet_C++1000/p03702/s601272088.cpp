#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int h[MAXN];

bool check(int k, int a, int b, int n)
{
    long long spells = 0;
    int over = a - b;
    for (int i = 0; i < n; i++)
    {
        spells += (max((long long) 0, (h[i] - (long long) b * k)) + over - 1)  / (over);
    }
    return spells <= k;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    int ans = 0;
    for (int jump = 1E9; jump > 0; jump /= 2)
    {
        while ((long long) ans + jump <= 1E9 && !check(ans + jump, a, b, n))
            ans += jump;
    }
    cout << ans + 1 << endl;
    return 0;
}

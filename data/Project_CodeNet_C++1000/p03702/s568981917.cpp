#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
long n, a, b;
long H[MAX_N + 1];
bool check(long long mb)
{
    long long cnt = 0;
    long long x = a - b;
    for (int i = 0; i < n; i++)
    {
        long long h = H[i] - mb * b;
        if (h <= 0)
            continue;
        cnt += (h + x - 1) / x;
    }
    if (cnt <= mb)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
    }
    long long lb = 0, ub = 1000000000;
    while (ub - lb > 1)
    {
        long long mb = (lb + ub) / 2;
        if (check(mb))
        {
            ub = mb;
        }
        else
        {
            lb = mb;
        }
    }
    cout << ub << endl;
}

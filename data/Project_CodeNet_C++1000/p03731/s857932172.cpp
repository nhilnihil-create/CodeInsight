#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, t, i, ans = 0;
    cin >> n >> t;
    vector<long> time(n);
    for (i = 0; i < n; i++)
    {
        cin >> time.at(i);
    }
    for (i = 0; i < n - 1; i++)
    {
        if (t + time.at(i) > time.at(i + 1))
        {
            ans += time.at(i + 1) - time.at(i);
        }
        else
        {
            ans += t;
        }
    }
    ans += t;
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }

    vector<int64_t> s(n);
    int64_t acc = 0;
    for (int i = 0; i < n; i++)
    {
        acc += a.at(i);
        s.at(i) = acc;
    }

    int64_t res_p = 0;
    int64_t acc_p = 0;
    for (int i = 0; i < n; i++)
    {
        int64_t si = s.at(i) + acc_p;
        if (i % 2 == 0)
        {
            if (si > 0)
                continue;
            res_p += 1 - si;
            acc_p += 1 - si;
        }
        else
        {
            if (si < 0)
                continue;
            res_p += si + 1;
            acc_p -= si + 1;
        }
    }

    int64_t res_n = 0;
    int64_t acc_n = 0;
    for (int i = 0; i < n; i++)
    {
        int64_t si = s.at(i) + acc_n;
        if (i % 2 == 0)
        {
            if (si < 0)
                continue;
            res_n += si + 1;
            acc_n -= si + 1;
        }
        else
        {
            if (si > 0)
                continue;
            res_n += 1 - si;
            acc_n += 1 - si;
        }
    }

    cout << min(res_p, res_n) << endl;
}
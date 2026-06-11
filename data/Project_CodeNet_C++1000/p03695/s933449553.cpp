#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, a, min = 0, count = 0, b;
    cin >> N;
    vector<int> v;
    vector<bool> color;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i <= 7; i++)
    {
        color.push_back(false);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= 1 && v[i] <= 399)
        {
            color[0] = true;
            continue;
        }

        if (v[i] >= 400 && v[i] <= 799)
        {
            color[1] = true;
            continue;
        }

        if (v[i] >= 800 && v[i] <= 1199)
        {
            color[2] = true;
            continue;
        }

        if (v[i] >= 1200 && v[i] <= 1599)
        {
            color[3] = true;
            continue;
        }

        if (v[i] >= 1600 && v[i] <= 1999)
        {
            color[4] = true;
            continue;
        }

        if (v[i] >= 2000 && v[i] <= 2399)
        {
            color[5] = true;
            continue;
        }

        if (v[i] >= 2400 && v[i] <= 2799)
        {
            color[6] = true;
            continue;
        }

        if (v[i] >= 2800 && v[i] <= 3199)
        {
            color[7] = true;
            continue;
        }

        if (v[i] >= 3200)
        {
            min++;
            count++;
        }
    }

    for (int i = 0; i < color.size(); i++)
    {
        if (color[i])
        {
            count++;
        }
    }

    b = count - min;
    if (b == 0)
    {
        b = 1;
    }

    cout << b << " " << count;
}
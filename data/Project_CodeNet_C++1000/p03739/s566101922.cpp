#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long a[n], s1[n], s2[n], m = 0, p = 0;
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++)
    {
        if (i > 0) s1[i] = s1[i - 1] + a[i];
        else s1[i] = a[i];
        if (i % 2 == 0)
        {
            if (s1[i] >= 0) 
            {
                long long k = s1[i] + 1;
                s1[i] = -1;
                m += k;
            }
        }
        else
        {
            if (s1[i] <= 0)
            {
                long long k = 1 - s1[i];
                s1[i] = 1;
                m += k;
            }
        }
    }
    for (long long i = 0; i < n; i++)
    {
        if (i > 0) s2[i] = s2[i - 1] + a[i];
        else s2[i] = a[i];
        if (i % 2 == 1)
        {
            if (s2[i] >= 0) 
            {
                long long k = s2[i] + 1;
                s2[i] = -1;
                p += k;
            }
        }
        else
        {
            if (s2[i] <= 0)
            {
                long long k = 1 - s2[i];
                s2[i] = 1;
                p += k;
            }
        }
    }
    cout << min(m, p);
}
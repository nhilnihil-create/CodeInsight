#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, k=0;
    cin >> n >> m;
    long long A[n], K[m+1], M[m+1];
    long long S=0, Mi=0, R=2000000000000;
    for (int i = 0; i <= m; i++)
    {
        K[i] = 0;
        M[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i != 0)
        {
            a = A[i]+1;
            if (a > m)
            {
                a -= m;
            }
            K[a]--;
            b = A[i];
            if (A[i] < A[i-1])
            {
                b += m;
            }
            M[a] += b-A[i-1]-1;
            a = A[i-1] + 2;
            if (a > m)
            {
                a -= m;
            }
            K[a]++;
            if (A[i] < A[i-1])
            {
                Mi += m - A[i-1];
                S += m - A[i-1] + A[i];
                if (A[i-1] != m)
                {
                    k++;
                }
            }
            else
            {
                S += A[i] - A[i-1];
            }
        }
    }
    R = S-Mi;
    for (int i = 2; i <= m; i++)
    {
        Mi -= M[i];
        k += K[i];
        Mi += k;
        if (S-Mi < R)
        {
            R = S-Mi;
        }
    }
    cout << R;
    return 0;
}

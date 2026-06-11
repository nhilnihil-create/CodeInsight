#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    char c;
    cin >> s;
    int n, a, I;
    n = s.length();
    int D[n+1], P[n+1], K[n+1], N[26][n+1];
    D[0] = 0;
    for (int i = 0; i < 26; i++)
    {
        N[i][n] = n;
        N[i][n-1] = n;
    }
    for (int i = n-2; i >= 0; i--)
    {
        for (int y = 0; y < 26; y++)
        {
            N[y][i] = N[y][i+1];
        }
        a = s[i+1] - 'a';
        N[a][i] = i+1;
    }
    D[n] = 0;
    for (int i = n-1; i >= 0; i--)
    {
        D[i] = 1000000;
        for (int y = 0; y < 26; y++)
        {
            if (D[N[y][i]] + 1 < D[i])
            {
                D[i] = D[N[y][i]] + 1;
                P[i] = N[y][i];
                K[i] = y;
            }
        }
    }
    int M = 1000000;
    a = s[0] - 'a';
    N[a][0] = 1;
    for (int y = 0; y < 26; y++)
    {
        if (D[N[y][0]] + 1 < M)
        {
            M = D[N[y][0]] + 1;
            c = 'a' + y;
            I = N[y][0];
        }
    }
    string r="";
    r += c;
    while (I != n)
    {
        c = K[I] + 'a';
        r += c;
        I = P[I];
    }
    cout << r;
    return 0;
}

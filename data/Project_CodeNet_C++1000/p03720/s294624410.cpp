#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int c[n];
    for (int i = 0; i < n; i++)
        c[i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        c[a - 1]++;
        c[b - 1]++;
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << endl;
}

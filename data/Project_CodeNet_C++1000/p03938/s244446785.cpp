#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 20002;

int n;

int k;

int p[N_MAX];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> k;
        p[k] = i;
    }
    for(int i = 1; i <= n; i++)
        cout << i * (n + 1) << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++)
        cout << p[i] + n * (n + 1) - i * (n + 1) << " ";
    cout << "\n";
    return 0;
}

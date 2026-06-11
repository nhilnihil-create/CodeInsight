#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> c(n);


    for (int i = 0; i < n; i++) cin >> c[i];

    int dist = 0;
    for (int i = 0; i < n; i++)
    {
        dist += 2*min(c[i], abs(k-c[i]));
    }
    cout << dist << '\n';
    return 0;
}


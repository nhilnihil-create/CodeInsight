#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    long long res = k;
    for (int i = 1; i < n; i++)
    {
        res *= (k - 1);
    }

    cout << res << endl;

    return 0;
}

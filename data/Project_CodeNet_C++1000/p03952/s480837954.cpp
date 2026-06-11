#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;

    if (x == 1 || x == 2 * N - 1)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    int t = 1;
    for (int i = 0; i < N - 2; i++)
    {
        if (t == x - 1 || t == x || t == x + 1)
            t = x + 2;
        cout << t << endl;
        t++;
    }
    cout << x - 1 << endl;
    cout << x << endl;
    cout << x + 1 << endl;
    for (int i = 0; i < N - 2; i++)
    {
        if (t == x - 1 || t == x || t == x + 1)
            t = x + 2;
        cout << t << endl;
        t++;
    }
    return 0;
}

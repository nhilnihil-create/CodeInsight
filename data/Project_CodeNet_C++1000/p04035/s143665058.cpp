#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i);
    }

    int last = -1;
    for (int i = 0; i < N - 1; i++)
    {
        if (a.at(i) + a.at(i + 1) >= L)
        {
            last = i;
        }
    }

    if (last < 0)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << "Possible" << endl;
        for (int i = 0; i < last; i++)
        {
            cout << i + 1 << endl;
        }
        for (int i = N - 2; i >= last; i--)
        {
            cout << i + 1 << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, a, j;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        v[i] = a;
    }
    if (v[0] == 2)
    {
        cout << 1 << endl;
    }
    else
    {
        j = v[0] - 1;
        for (int k = 0; k < N; k++)
        {
            if (v[j] == 2)
            {
                cout << k + 2 << endl;
                break;
            }
            else if (k == N - 1)
            {
                cout << -1 << endl;
            }
            j = v[j] - 1;
        }
    }
}

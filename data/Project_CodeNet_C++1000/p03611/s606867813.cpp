#include <bits/stdc++.h>
using namespace std;

int N;
int f[100010];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        f[a]++;
    }

    int ma = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (i + 2 < 100000)
        {
            int sum = f[i] + f[i + 1] + f[i + 2];
            ma = max(ma, sum);
        }
    }

    cout << ma << endl;

    return 0;
}

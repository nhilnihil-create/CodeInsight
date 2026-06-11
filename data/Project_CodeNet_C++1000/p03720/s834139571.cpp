#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int ans = 0;
    int a[55], b[55];
    for (int i = 0; i < 55; i++)
    {
        a[i] = -1;
        b[i] = -1;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(i==a[j]||i==b[j])
                ans++;
        }
        cout << ans << endl;
        ans = 0;
    }

    return 0;
}
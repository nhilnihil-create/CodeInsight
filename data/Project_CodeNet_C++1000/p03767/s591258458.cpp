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
    int N, x;
    cin >> N;
    long long ans = 0;

    int a[300010];
    for (int i = 0; i < 300010; i++)
    {
        a[i] = -1;
    }

    for (int i = 0; i < 3 * N; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 300010);

    for (int i = 0; i < N; i++)
    {
        ans += a[300010 - 2 - 2 * i];
        
    }

    cout << ans << endl;

    return 0;
}
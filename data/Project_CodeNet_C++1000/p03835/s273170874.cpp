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
    int K, S, length, max;
    cin >> K >> S;
    int x, y, z;
    int ans = 0;

    for (int a = 0; a <= K; a++)
    {
        for (int b = 0; b <= K; b++)
        {
            z = S - a - b;
            if (z >= 0 && z <= K)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
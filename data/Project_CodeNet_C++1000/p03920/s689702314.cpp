#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <functional>
#include <unordered_map>
#include <random>
#include <iomanip>
#include <cstdlib>

using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int k;
    for (int i = 1; i <= n; i++) if (((i * (i + 1)) >> 1) >= n)
    {
        k = i;
        break;
    }
    for (int i = k; i > 0; i--)
    {
        if (n - i >= 0)
        {
            cout << i << endl;
            n -= i;
        }
    }
    return 0;
}
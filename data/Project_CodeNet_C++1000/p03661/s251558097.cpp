#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <iterator>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    i64 a = 0, b = 0;

    for (int i = 0; i < n; i++)
        a += arr[i];

    i64 gap = abs(a - 2 * arr[0]);

    for (int i = 0; i < n - 1; i++)
    {
        a -= arr[i];
        b += arr[i];

        gap = min(gap, abs(a - b));
    }

    printf("%lld\n", gap);

    return 0;
}
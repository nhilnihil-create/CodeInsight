#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
#define ALL(X) X.begin(), X.end()
using lint = long long;
template <typename T>
void print_container(std::vector<T> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    lint n;
    scanf("%lld", &n);
    std::vector<lint> a(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    lint ans = 0;

    lint rem = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            rem = 0;
            continue;
        }
        ans += ((a[i] + rem) / 2);
        rem = (a[i] + rem) % 2;
    }

    std::cout << ans << "\n";

    return 0;
}

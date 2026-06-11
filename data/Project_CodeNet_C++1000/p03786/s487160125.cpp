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

    std::vector<lint> creatures(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &creatures[i]);
    }

    std::sort(ALL(creatures));
    std::vector<lint> cumsum(n);
    std::partial_sum(ALL(creatures), cumsum.begin());

    lint ans{0};

    for (int i = 0; i < n - 1; ++i)
    {
        if (cumsum[i] * 2 >= creatures[i + 1])
        {
            ans++;
        }
        else
        {
            ans = 0;
        }
    }

    std::cout << ans + 1 << "\n";

    return 0;
}

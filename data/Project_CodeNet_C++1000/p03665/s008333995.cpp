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
using lint = long long;

int main()
{
    lint n, p;

    scanf("%lld", &n);
    scanf("%lld", &p);

    std::vector<lint> a(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    lint odd, even;
    odd = even = 0;

    for (auto a_e : a)
    {
        if (a_e % 2 == 0)
            even++;
        else
            odd++;
    }

    std::vector<lint> odd_comb;
    odd_comb.push_back(1);

    lint c = 1;

    for (int i = 1; i <= odd / 2; ++i)
    {
        c *= odd - (i - 1);
        c /= i;
        odd_comb.push_back(c);
    }

    lint even_pattern = pow(2, even);

    lint odd_pattern = 0;

    if (p == 0)
    {
        for (int i = 0; i <= odd; i += 2)
        {
            if (i <= odd / 2)
            {
                odd_pattern += odd_comb[i];
            }
            else
            {
                odd_pattern += odd_comb[odd - i];
            }
        }
    }
    else
    {
        for (int i = 1; i <= odd; i += 2)
        {
            if (i <= odd / 2)
            {
                odd_pattern += odd_comb[i];
            }
            else
            {
                odd_pattern += odd_comb[odd - i];
            }
        }
    }

    printf("%lld", odd_pattern * even_pattern);

    return 0;
}

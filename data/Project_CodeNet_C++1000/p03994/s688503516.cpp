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
    std::string s;
    std::cin >> s;

    lint k;
    scanf("%lld", &k);

    lint rem = k;

    for (int i = 0; i < s.size(); ++i)
    {
        if (i == s.size() - 1)
        {
            s[i] = (s[i] - 'a' + rem) % 26 + 'a';
        }
        else if ((26 - (s[i] - 'a')) % 26 > rem)
        {
            continue;
        }
        else
        {
            rem -= (26 - (s[i] - 'a')) % 26;
            s[i] = 'a';
        }
    }

    std::cout << s << "\n";
    return 0;
}

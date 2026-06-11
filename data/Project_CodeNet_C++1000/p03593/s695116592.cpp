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
    lint h, w;
    scanf("%lld", &h);
    scanf("%lld", &w);

    std::vector<lint> alpha(26, 0);
    std::vector<std::string> mat(h);
    std::string s;

    for (int i = 0; i < h; ++i)
    {
        std::cin >> s;

        mat[i] = s;
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            alpha[lint(char(mat[i][j]) - 'a')]++;
        }
    }

    lint four, two, one;

    if (h % 2 == 1 && w % 2 == 1)
    {
        one = 1;
        two = (h - 1) / 2 + (w - 1) / 2;
        four = (h * w - two * 2 - 1) / 4;
    }
    else if (h % 2 == 1 && w % 2 == 0)
    {
        one = 0;
        two = w / 2;
        four = (h - 1) * w / 4;
    }
    else if (h % 2 == 0 && w % 2 == 1)
    {
        one = 0;
        two = h / 2;
        four = (w - 1) * h / 4;
    }
    else
    {
        one = 0;
        two = 0;
        four = h * w / 4;
    }

    for (int i = 0; i < 26; ++i)
    {
        lint rem = alpha[i];
        if (rem == 0)
            continue;

        while (rem >= 4 && four >= 1)
        {
            rem -= 4;
            four--;
        }
        while (rem >= 2 && two >= 1)
        {
            rem -= 2;
            two--;
        }
        if (rem % 2 != 0)
        {
            one--;
        }
    }

    if (four == 0 && two == 0 && one == 0)
    {
        std::cout << "Yes"
                  << "\n";
    }
    else
    {
        std::cout << "No"
                  << "\n";
    }

    return 0;
}

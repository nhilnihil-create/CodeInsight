#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

char col[4] = {'R', 'G', 'B', 'Y'};
char ans[1005][1005];
int h, w, d;

void fill_triangle(int cx, int cy, int dr, char cr)
{
    for (int i = cx - d / 2 + 1; i < cx + d / 2; i++)
    {
        int R = d / 2 - abs(cx - i);
        for (int j = 0; j < R; j++)
        {
            if (i >= 0 && i < h && cy + dr * j >= 0 && cy + dr * j < w)
                ans[i][cy + dr * j] = cr;
        }
    }
}

int main()
{
    scanf("%d%d%d",&h,&w,&d);

    if (d & 1)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                printf("%c", col[(i + j) & 1]);
            }
            printf("\n");
        }

        return 0;
    }
    else if (d % 4 == 2)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                printf("%c", col[(j + i / 2 * 2) % 4]);
            }
            printf("\n");
        }
        return 0;
    }
    else
    {
        for (int i = d / 2 - 1; i < h + 2 * d; i += d)
        {
            for (int j = 0; j < w + 2 * d; j += d)
            {
                fill_triangle(i, j, 1, col[((i + j + d) / d) & 1]);
                fill_triangle(i, j - 1, -1, col[((i + j + d) / d) & 1]);
            }
        }

        for (int i = -1; i < h + 2 * d; i += d)
        {
            for (int j = d / 2; j < w + 2 * d; j += d)
            {
                fill_triangle(i, j, 1, col[(((i + j + d) / d) & 1) + 2]);
                fill_triangle(i, j - 1, -1, col[(((i + j + d) / d) & 1) + 2]);
            }
        }

        for (int i = 0; i < h; i++) printf("%s\n", ans[i]);
    }
}

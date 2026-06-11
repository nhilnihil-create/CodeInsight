#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 1e5 + 100;
int a[N];
    
int n;
/*
map <pair <int, int>, int> dp;

// 1 - Win, 0 - Lose
int solve(int x, int y)
{
    if (a[x] <= y)
        return 1;
    if (dp.count(make_pair(x, y)))
        return 1;
    int ans = 0;
    if (abs(x - y) == 0)
    {
        if (!solve(x + 1, y) || !solve(x, y + 1))
            ans = 1;
    }
    else if (y == x + 1)
    {
        if (!solve(x + 1, y))
            ans = 1;
        else if (a[x + 1] <= y + 1 && (a[x] - y) % 2 == 0)
            ans = 1;
    }
    else if (y + 1 == x)
    {
        if (!solve(x, y + 1))
            ans = 1;
        else if (a[x + 1] <= y + 1)
        {
            int ptr = x;
            while (a[ptr] > y)
                ptr++;
            if ((ptr - x) % 2 == 0)
                ans = 1;
        }
    }
    dp[make_pair(x, y)] = ans;
    return ans;
}
*/


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);

//    int ans = solve(0, 0);

    int ans = 0;
    
    for (int t = 0; t < 2; t++)
    {
        int x = t;
        int y = t ^ 1;

        while (a[x] > y)
        {
            x++;
            y++;
        }
        x--;
        y--;
        if (x >= 0 && y >= 0)
        {
            ans = 1;
            if ((a[x] - y) % 2 == 0)
                ans = 0;
            int ptr = x;
            while (a[ptr] > y)
                ptr++;
            if ((ptr - x) % 2 == 0)
                ans = 0;
        }

        if (ans)
            break;
    }
    
    
    printf(ans ? "First\n" : "Second\n");



	return 0;
}



/*************************************
 * problem:      AT2165 Median Pyramid Hard. 
 * user ID:      63720.
 * user name:    Jomoo.
 * time:         2019-08-13.
 * language:     C++.
 * upload place: Luogu.
*************************************/ 

#include <bits/stdc++.h>
using namespace std;

typedef signed char          int8;
typedef unsigned char       uint8;
typedef short                int16;
typedef unsigned short      uint16;
typedef int                  int32;
typedef unsigned            uint32;
typedef long long            int64;
typedef unsigned long long  uint64;

template <typename Int>
inline Int read()       
{
    Int flag = 1;
    char c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
	return init * flag;
}

template <typename Int>
inline void write(Int x)
{
    if (x < 0) putchar('-'), x = ~x + 1;
    if (x > 9) write(x / 10);
    putchar((x % 10) | 48);
}  

template <typename Int>
inline void write(Int x, char nextch)
{
    write(x);
    putchar(nextch);
}

int n, a[200000 + 7];

int turn(int Id1, int Id2, int MidNum) 
{
    return (a[Id1] >= MidNum) + (a[Id2] >= MidNum);
}

bool check(int lim)
{
    for (int i = 0; i < n - 1; i++) {
        if (turn(n - i, n - i - 1, lim) == 2 || turn(n + i, n + i + 1, lim) == 2) return true;
        if (turn(n - i, n - i - 1, lim) == 0 || turn(n + i, n + i + 1, lim) == 0) return false;
    }
    return a[1] >= lim;
}

int main()
{
    n = read<int>();
    for (int i = 1; i <= 2 * n - 1; i++) 
        a[i] = read<int>();
    int l = 1, r = 2 * n - 1, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    write(ans);
    return 0;
}
/*************************************
 * problem:      AT2163.
 * user ID:      63720.
 * user name:    Jomoo.
 * time:         2019-mm-dd.
 * language:     C++.
 * upload place: Luogu.
*************************************/ 

#include <bits/stdc++.h>
using namespace std;
#define puts_return(x) { puts(x); return 0; }

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

int n, x;
bool used[200003];

int main()
{
    n = read<int>();
    x = read<int>();
    if (x == 1 || x == 2 * n - 1) puts_return("No");
    puts("Yes");
    used[x - 1] = true;
    used[x] = true;
    used[x + 1] = true;
    if (x == 2) used[x + 2] = true;
    else used[x - 2] = true;
    int pos = 1;
    for (int i = 1; i <= n - 2 - (x == 2); i++) {
        while (used[pos]) pos++;
        write(pos, 10);
        pos++;
    }
    if (x == 2 && n != 2) write(x + 2, 10);
    write(x - 1, 10);
    write(x, 10);
    write(x + 1, 10);
    if (x != 2) write(x - 2, 10);
    for (int i = n + 2 + (x != 2); i <= 2 * n - 1; i++) {
        while (used[pos]) pos++;
        write(pos, 10);
        pos++;
    }   
    return 0;
}

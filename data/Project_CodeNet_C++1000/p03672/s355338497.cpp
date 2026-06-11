#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    char str[222];
    scanf("%s", str);
    int n = strlen(str);
    for (int i = n - 2; i; i -= 2)
    {
        if (strncmp(str, str + i / 2, i / 2) == 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
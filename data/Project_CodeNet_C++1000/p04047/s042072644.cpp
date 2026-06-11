#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e6 + 10;
const double eps = 1e-8;
const ll mod = 1e9 + 7;
const ull base = 131;
const ull mod1 = 1e9 + 9;
const ull mod2 = 1610612741;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}


int n;
int a[maxn];

int main()
{
    scanf("%d", &n);
    n *= 2;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    sort(a+1, a+n+1);
    int sum = 0;
    for (int i = 1; i <= n; i+=2)
        sum += a[i];
    printf("%d\n", sum);
    return 0;
}

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

char s[maxn];
bool t[4];

int main()
{
    scanf("%s", s+1);
    for (int i = 1; s[i]; ++i)
        if (s[i] == 'W') t[0] = 1;
        else if (s[i] == 'S') t[1] = 1;
        else if (s[i] == 'E') t[2] = 1;
        else t[3] = 1;
    if (t[0]^t[2] || t[1]^t[3]) printf("No\n");
    else printf("Yes\n"); 
    return 0;
}


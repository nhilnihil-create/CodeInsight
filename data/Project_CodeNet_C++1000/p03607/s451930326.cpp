#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int n, ptr, res;
int a[100000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    sort(a, a+n);
    while(ptr < n)
    {
        int cc = a[ptr], f = 0;
        while (ptr < n && a[ptr] == cc) ++f, ++ptr;
        res += f % 2;
    }
    printf("%d\n", res);
    return 0;
}

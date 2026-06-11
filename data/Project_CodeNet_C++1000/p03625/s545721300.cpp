#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100010;

int n, idx, res[6], a[N];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = n - 1; i > 0; --i)
    {
        if(a[i] == a[i - 1])
        {
            res[idx++] = a[i];
            if(idx == 2) break;
            --i;
        }
    }
    if(idx == 2)
        cout << 1ll * res[0] * res[1];
    else
        cout << 0;
    return 0;
}

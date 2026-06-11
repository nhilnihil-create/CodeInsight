#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int a[N];

int q[N];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        q[a[i]]++;
    int minu;
    if (a[n] % 2 == 1)
    {
        for (int i = a[n]; i >= (a[n] / 2) + 1; --i)
        {
            if (q[i] < 2)
                return false;
            q[i] -= 2;
        }
        minu = (a[n] / 2) + 2;
    }
    else
    {
        for (int i = a[n]; i >= (a[n] / 2) + 1; --i)
        {
            if (q[i] < 2)
                return false;
            q[i] -= 2;
        }
        if (q[a[n] / 2] < 1)
            return false;
        q[a[n] / 2] -= 1;
        minu = (a[n] / 2) + 1;
    }
    for (int i = 1; i < minu; ++i)
    {
        if (q[i])
            return false;
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    if (solv())
        printf("Possible\n");
    else
    {
        while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
        printf("Impossible\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}

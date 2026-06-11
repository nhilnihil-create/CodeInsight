#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
char a[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    int ans = n;
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'S')
            ++q;
        else
        {
            if (q)
            {
                ans -= 2;
                --q;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}

#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long ans = 0;
    long long yans = 0;
    stack<pair<int, int> > s;
    for (int i = 1; i <= n; ++i)
    {
        int q = 1;
        while (!s.empty() && a[i] <= s.top().first)
        {
            yans -= (s.top().first * 1LL * s.top().second);
            q += s.top().second;
            s.pop();
        }
        yans += (q * 1LL * a[i]);
        s.push(m_p(a[i], q));
        ans += yans;
    }
    printf("%lld\n", ans);
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

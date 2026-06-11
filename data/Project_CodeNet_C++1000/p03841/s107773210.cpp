#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 600;
int ai[N], od[N];
int remin[N];
int fin[N * N], cnt[N][N];
stack <int> Q;
int comp(int a, int b)
{
    return ai[a] < ai[b];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> ai[i];
    for (int i = 1; i <= n; ++ i) od[i] = i;
    sort(od + 1, od + n + 1, comp); od[n + 1] = n + 1;
    ai[od[n + 1]] = n * n + 1;
    for (int i = 1; i <= n + 1; ++ i)
        remin[i] = ai[od[i]] - ai[od[i - 1]] - 1;
    for (int i = 1, v = (n - 1) * n / 2; i <= n; ++ i)
    {
        int x = od[i] - 1;
        for (int j = 1; j <= i; ++ j)
        {
            int k = min(remin[j], x);
            cnt[j][od[i]] += k;
            remin[j] -= k; x -= k;
        }
        for (int j = 1; j <= n - od[i]; ++ j) Q.push(od[i]);
        v -= n - od[i];
        while (Q.size() + n - i - 1 + v + ai[od[i + 1]] > n * n)
        {
            if (Q.empty()) return puts("No"), 0;
            cnt[i + 1][Q.top()] ++;
            remin[i + 1] --;
            Q.pop();
        }
    }
    for (int i = n + 1; i; -- i)
        while (remin[i])
        {
            if (Q.empty()) return puts("No"), 0;
            cnt[i][Q.top()] ++;
            remin[i] --;
            Q.pop();
        }
    puts("Yes");
    for (int i = 1; i <= n + 1; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
            for (int k = 1; k <= cnt[i][j]; ++ k)
                cout << j << " ";
        if (i != n + 1) cout << od[i] << " ";
    }

}

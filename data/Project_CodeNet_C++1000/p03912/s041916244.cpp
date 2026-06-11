#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

int n, m, mod[1000001], bo[1000001], ar[1000001], sum[1000001];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        ar[x]++;
    }

    for(int i = 1; i <= 1e5; i++)
        bo[i] = ar[i] % 2;

    for(int i = 1e5; i >= 0; i--)
        mod[i] = ar[i] + mod[i + m], bo[i] = bo[i] + bo[i + m], sum[i] = ar[i] / 2 + sum[i + m];

    long long ans = 0;
    for(int i = 1; i <= m / 2; i++)
    {
        if(i * 2 == m)
            continue;
        int a = i, b = m - i;
        if(bo[a] > bo[b])
            swap(a, b);

        ans += sum[b] + bo[a];
        bo[b] -= bo[a];

        if(sum[a] * 2 <= bo[b])
        {
            ans += sum[a] * 2;
        }else
        {
            ans += bo[b] / 2 * 2;
            ans += sum[a] - bo[b] / 2;
        }
        //cout << ans << endl;
    }
    ans += (mod[0] / 2);
    if(m % 2 == 0)
        ans += (mod[m / 2] / 2);

    cout << ans;
    return 0;
}

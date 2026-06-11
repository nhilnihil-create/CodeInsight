#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;

int n, m, a[N], label[N], base[N], temp[N];
ll k;
ll x[N], d[N], ans[N];

void by_p()
{
    for(int i = 1; i <= m; i++)
        swap(label[a[i]], label[a[i] + 1]);
}

void by_itself()
{
    for(int i = 1; i <= n; i++)
        temp[i] = label[label[i]];
    for(int i = 1; i <= n; i++)
        label[i] = temp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
        d[i] = x[i] - x[i - 1];
        label[i] = i;
        base[i] = i;
    }

    cin >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
        swap(base[a[i]], base[a[i] + 1]);
    }

    vector <int> b;
    while(k)
    {
        b.pb(k & 1);
        k /= 2;
    }
    reverse(b.begin(), b.end());
    for(int x: b)
    {
        by_itself();
        if(x)
            by_p();
    }

    for(int i = 1; i <= n; i++)
        ans[i] = d[label[i]];

    for(int i = 1; i <= n; i++)
        ans[i] = ans[i] + ans[i - 1];

    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;

    return 0;
}

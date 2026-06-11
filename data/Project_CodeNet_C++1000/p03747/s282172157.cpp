/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;

int n;
ll L, t;

ll x[N_MAX];

int w[N_MAX];

vector <int> v1, v2;

int ans[N_MAX];

int last1 (int pos)
{
    int l = 0, r = (int)v1.size() - 1;
    while(l < r)
    {
        int mid = ((l + r + 1) >> 1);
        if(x[v1[mid]] > pos)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

int last2 (int pos)
{
    int l = 0, r = (int)v2.size() - 1;
    while(l < r)
    {
        int mid = ((l + r + 1) >> 1);
        if(x[v2[mid]] > pos)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

int cnt1 (int l, int r)
{
    l = (l % L + L) % L;
    r = (r % L + L) % L;
    if(l <= r)
        return last1(r) - last1(l - 1);
    else if(l - r > 1)
        return (int)v1.size() - 1 - cnt1(r + 1, l - 1);
    return 0;
}

int cnt2 (int l, int r)
{
    l = (l % L + L) % L;
    r = (r % L + L) % L;
    if(l <= r)
        return last2(r) - last2(l - 1);
    else if(l - r > 1)
        return (int)v2.size() - 1 - cnt2(r + 1, l - 1);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> L >> t;
    v1.push_back(0);
    v2.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> w[i];
        if(w[i] == 1)
            v1.push_back(i);
        else
            v2.push_back(i);
    }
    for(int i = 1; i <= n; i++)
        if(w[i] == 1)
        {
            int pos = (x[i] + 2LL * t) % L;
            int c = (cnt2(x[i], pos) + (2LL * t / L) * ((int)v2.size() - 1) % n) % n;
            int j = ((i - 1 + c) % n + n) % n + 1;
            ans[j] = ((pos - t) % L + L) % L;
        }
        else
        {
            int pos = ((x[i] - 2LL * t) % L + L) % L;
            int c = (cnt1(pos, x[i]) % n + (2LL * t / L) * ((int)v1.size() - 1) % n) % n;
            int j = ((i - 1 - c) % n + n) % n + 1;
            ans[j] = (pos + t) % L;
        }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
ll lazy1[4 * N];
int dif[4 * N];
ll lazy2[4 * N];

void prop1(int node, int l, int r)
{
    if(lazy1[node] == 0)
        return;
    if(l == r)
    {
        return;
    }
    else
    {
        lazy1[node * 2 + 1] += lazy1[node];
        dif[node * 2 + 1] += dif[node];
        int mid = (l + r) / 2;
        lazy1[node * 2] += (r - mid) * dif[node] + lazy1[node];
        dif[node * 2] += dif[node];
        dif[node] = 0;
        lazy1[node] = 0;
    }
}

void update1(int node, int l, int r, int st, int en, int val)
{
    prop1(node, l, r);
    if(st > r || en < l)
        return;
    if(st <= l && r <= en)
    {
        lazy1[node] += (en - r) + val;
        dif[node] += 1;
        return;
    }
    int mid = (l + r) / 2;
    update1(node * 2, l, mid, st, en, val);
    update1(node * 2 + 1, mid + 1, r, st, en, val);
}

void prop2(int node, int l, int r)
{
    if(lazy2[node] == 0)
        return;
    if(l == r)
    {
        return;
    }
    else
    {
        lazy2[node * 2] += lazy2[node];
        lazy2[node * 2 + 1] += lazy2[node];
        lazy2[node] = 0;
        return;
    }
}

void update2(int node, int l, int r, int st, int en, int val)
{
    prop2(node, l, r);
    if(st > r || en < l)
        return;
    if(st <= l && r <= en)
    {
        lazy2[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    update2(node * 2, l, mid, st, en, val);
    update2(node * 2 + 1, mid + 1, r, st, en, val);
}

ll query(int node, int l, int r, int idx)
{
    if(idx > r || idx < l)
        return 1e18;
    prop1(node, l, r);
    prop2(node, l, r);
    if(l == r)
        return lazy1[node] + lazy2[node];
    int mid = (l + r) / 2;
    return min(query(node * 2, l, mid, idx), query(node * 2 + 1, mid + 1, r, idx));
}

int arr[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++)
    {
        int first = arr[i - 1];
        int second = arr[i];
        if(second > first)
        {
            update1(1, 1, m, first + 1, second, 1);
            update2(1, 1, m, 1, first, second - first);
            if(second < m)
                update2(1, 1, m, second + 1, m, second - first);
        }
        else
        {
            update1(1, 1, m, 1, second, 1);
            if(first < m)
                update1(1, 1, m, first + 1, m, second + 1);
            update2(1, 1, m, second + 1, first, m - first + second);
        }
    }
    ll ans = 1e18;
    for(int i = 1; i <= m; i++)
    {
        ll cur = query(1, 1, m, i);
        ans = min(ans, cur);
    }
    cout << ans;
    return 0;
}

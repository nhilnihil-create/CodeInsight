#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
ll A, B;
ll arr[MAXN];

bool works (int x)
{
    ll ct = 0;
    for (int i = 0; i < N; i++)
    {
        ll nleft = arr[i] - x * B;
        if (nleft > 0)
            ct += (nleft - 1) / (A - B) + 1;
    }
    return ct <= x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int lo = 1, hi = 1e9;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (works (mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
}
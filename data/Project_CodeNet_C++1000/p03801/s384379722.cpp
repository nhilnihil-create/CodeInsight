#include <bits/stdc++.h>

#define N_MAX 100002
#define ll long long

using namespace std;

int n;

struct Pile
{
    ll cnt;
    int cntBigger;
    ll sumBigger;
    int index;
};

ll sum;

bool cmpCnt (const Pile &a, const Pile &b)
{
    return make_pair(a.cnt, a.index) > make_pair(b.cnt, b.index);
}
bool cmpIndex (const Pile &a, const Pile &b)
{
    return a.index < b.index;
}

Pile a[N_MAX];

set <int> s;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].cnt;
        a[i].index = i;
        sum += a[i].cnt;
    }
    sort(a + 1, a + n + 1, cmpCnt);
    for(int i = 1; i <= n; i++)
    {
        a[i].cntBigger = i;
        a[i].sumBigger = a[i - 1].sumBigger + a[i].cnt;
    }
    sort(a + 1, a + n + 1, cmpIndex);
    ll sumAns = 0;
    for(int i = 1; i <= n; i++)
    {
        ll ans = max(0LL, sum - (a[i].sumBigger - a[i].cntBigger * a[i].cnt) - sumAns);
        sumAns += ans;
        cout << ans << "\n";
    }
    return 0;
}

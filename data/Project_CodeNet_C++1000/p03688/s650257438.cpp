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

int a[N_MAX];

int cnt[N_MAX];

int mx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        cnt[a[i]]++;
    }
    if(cnt[mx] == n)
    {
        if(mx * 2 <= n || mx == n - 1)
            cout << "Yes\n";
        else
            cout << "No\n";
        return 0;
    }
    int c = cnt[mx - 1];
    int cntMi = c + (c < n);
    int cntMx = c + (n - c) / 2;
    if(cntMi - 1 <= mx - 1 && mx - 1 <= cntMx - 1)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

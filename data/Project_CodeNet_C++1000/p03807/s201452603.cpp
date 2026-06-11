/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        cnt[(a & 1)]++;
    }
    if(cnt[1] & 1)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}

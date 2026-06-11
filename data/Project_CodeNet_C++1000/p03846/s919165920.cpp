/**
 * @author: shashankchdhry
 * @made:   2020-04-02 08:17:15 
**/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MOD = 1e9 + 7;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ump[temp]++;
    }

    ll ans = 1;

    bool flag = true;
    if (n%2 && ump[0] != 1)
        flag = false;
    int start = n%2?2:1;
    while (start < n && flag)
    {
        if (ump[start] != 2)
            flag = false;
        ans *= 2;
        ans %= MOD;
        start += 2;
    }
    if (flag)
        cout << ans << "\n";
    else
    {
        cout << 0 << "\n";
    }

    return 0;
}
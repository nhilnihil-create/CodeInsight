#include <bits/stdc++.h>
using namespace std;

#define fast_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define show(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ull unsigned long long
#define pi 3.141592654

int main()
{
    fast_IO
    int n, m, x, y; cin >> n >> m;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[i] = 1;
    unordered_set<int> us;
    us.insert(1);
    while (m--)
    {
        cin >> x >> y;
        auto find_x = us.find(x), find_y = us.find(y);
        if (find_x != us.end())
        {
            if (mp[x] == 1) us.erase(find_x);
            if (find_y == us.end()) us.insert(y);
        }
        mp[x]--; mp[y]++;
    }
    cout << us.size() << '\n';
    return 0;
}
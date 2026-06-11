#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    for(auto num : mp[1])
    {
        for(auto num2 : mp[num])
        {
            if(num2 == n)
            {
                cout << "POSSIBLE\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}

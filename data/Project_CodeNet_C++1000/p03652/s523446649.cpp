#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = n;
    set<int> s;
    for(int i = 0; i < m; i++)
    {
        map<int, int> tmp;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if(s.count(a[j][k]) == 0)
                {
                    tmp[a[j][k]]++;
                    break;
                }
            }
        }
        int count = 0;
        int target = 0;
        for(auto itr = tmp.begin(); itr != tmp.end(); itr++)
        {
            if(itr->second > count)
            {
                count = itr->second;
                target = itr->first;
            }
        }
        ans = min(ans, count);
        s.insert(target);
    }
    cout << ans << endl;
}

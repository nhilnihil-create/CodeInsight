#include <bits/stdc++.h>
using namespace std;
#define mh(s, g) abs(start.at(i).first - goal.at(j).first) + abs(start.at(i).second - goal.at(j).second)

int main()
{
    int n, m, i, j;
    cin >> n >> m;
    vector<pair<long, long>> start(n + 1);
    vector<pair<long, long>> goal(m + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> start.at(i).first >> start.at(i).second;
    }
    for (i = 1; i <= m; i++)
    {
        cin >> goal.at(i).first >> goal.at(i).second;
    }
    for (i = 1; i <= n; i++)
    {
        int ans = 1;
        long min = abs(start.at(i).first - goal.at(1).first) + abs(start.at(i).second - goal.at(1).second);
        for (j = 2; j <= m; j++)
        {
            long kouho = abs(start.at(i).first - goal.at(j).first) + abs(start.at(i).second - goal.at(j).second);
            if (min > kouho)
            {
                min = kouho;
                ans = j;
            }
        }
        cout << ans << endl;
    }
}
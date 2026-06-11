#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, a[500000];
long long MOD = 1e9 + 7;
long long ans = 1;
set<pair<int, int> > ss;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long before = 0;
    for (int i = 0; i < n; i++)
    {
        before++;
        ss.insert({a[i], 1});
        while (ss.size() > 1)
        {
            auto it1 = ss.end(), it2 = ss.end();
            it1--, it2--, it2--;
            pair<int, int> a = *it1, b = *it2;
            int firo = a.first - (a.second - 1) * 2;
            if (firo > b.first + 2)
                break;
            if (firo == b.first + 2)
            {
                ss.erase(a);
                ss.erase(b);
                ss.insert({a.first, a.second + b.second});
                break;
            }
            if (firo == b.first + 1)
            {
                ss.erase(a);
                ss.erase(b);
                ss.insert({a.first, a.second + b.second});
            }
        }
        int t = 0;
        while (ss.size())
        {
            auto it = ss.begin();
            pair<int, int> a = *it;
            if (a.first - (a.second - 1) * 2 <= 0)
            {
                ss.erase(a);
                ss.insert({a.first, a.second - 1});
                before--;
                t = 1;
            }
            else
            {
                break;
            }
        }
        //cout << before + t << " ";
        ans = ans * (before + t) % MOD;
    }
    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<set<int>> r(n + 1);
    deque<int> ans;
    set<int> s;

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        if (!i)
        {
            ans.push_back(a);
            ans.push_back(b);
            s.insert(a);
            s.insert(b);
        }
        if (s.find(b) == s.end())
            r[a].insert(b);
        if (s.find(a) == s.end())
            r[b].insert(a);
    }

    while (r[ans.back()].size())
    {
        int a = *r[ans.back()].begin();
        s.insert(a);
        ans.push_back(a);
        for (auto x : r[a])
        {
            if (s.count(x))
                r[a].erase(x);
        }
    }
    for (auto x : r[ans.front()])
    {
        if (s.count(x))
            r[ans.front()].erase(x);
    }

    while (r[ans.front()].size())
    {
        int a = *r[ans.front()].begin();
        s.insert(a);
        ans.push_front(a);
        for (auto x : r[a])
        {
            if (s.count(x))
                r[a].erase(x);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << ' ';
    cout << endl;

    return 0;
}

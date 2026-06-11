#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> v;
int ans[500 * 500 + 10];
int n;

bool emplace()
{
    queue <int> util, ramas;
    for (auto i : v) {
        for (int j(1); j < i.second; j++)
            util.push(i.second);
        for (int j(i.second + 1); j <= n; j++)
            ramas.push(i.second);
    }
    vector <int> nrpus(n + 1);
    for (int i(1); i <= n * n; i++) {
        if (ans[i]) {
            if (nrpus[ans[i]] != ans[i] - 1)
                return false;
            continue;
        }
        if (!util.empty()) {
            nrpus[util.front()]++;
            ans[i] = util.front();
            util.pop();
        }
        else {
            nrpus[ramas.front()]++;
            ans[i] = ramas.front();
            ramas.pop();
        }
    }
    return true;
}

int main()
{
    cin >> n;
    v.resize(n);
    for (int i(1); i <= n; i++) {
        cin >> v[i - 1].first;
        v[i - 1].second = i;
        ans[v[i - 1].first] = i;
    }

    sort(v.begin(), v.end());

    if (!emplace()) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    for (int i(1); i <= n * n; i++)
        cout << ans[i] << ' ';
    return 0;
}

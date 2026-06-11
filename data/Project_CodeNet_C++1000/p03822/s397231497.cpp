#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; ++i)
    {
        int p;
        cin >> p;
        --p;

        adj[p].push_back(i);
    }

    function<int(int)> solve = [&](int u) {
        int answer = 0;

        vector<int> d;
        for (auto v : adj[u])
        {
            d.push_back(solve(v));
        }

        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());

        int i = 0;
        for (auto x : d)
        {
            answer = max(answer, x + ++i);
        }

        return answer;
    };

    cout << solve(0) << endl;

    return 0;
}
#include <iostream>
#include <iomanip>
#include <queue>
#include <utility>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int k, t;
    cin >> k >> t;
    priority_queue<pair<int, int>> q;
    repi(i, t, 0)
    {
        int a;
        cin >> a;
        q.push({a, i});
    }
    int ans = 0, prev = -1;
    pair<int, int> tmp(0, -1);
    bool state = false;
    while (!state)
    {
        pair<int, int> cake = q.top();
        q.pop();
        if (cake.first > 0)
        {
            q.push(tmp);
            tmp = cake;
            tmp.first--;
        }
        if (cake.first == 0)
        {
            state = true;
        }
        else
        {
            ans++;
        }
    }
    cout << max(0, k - ans) << endl;
    return 0;
}
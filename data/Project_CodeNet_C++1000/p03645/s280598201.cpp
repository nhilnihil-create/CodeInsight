#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> graph(N);

    ll a, b;
    rep(0, i, M)
    {
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    queue<ll> que;
    for (auto g : graph.at(0))
    {
        que.push(g);
    }

    while (!que.empty())
    {
        ll x = que.front();
        que.pop();
        for (auto g : graph.at(x))
        {
            if (g == N - 1)
            {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
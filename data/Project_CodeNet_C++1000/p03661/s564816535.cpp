#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <random>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
#include <cstdlib>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
//const double EPS = 1e(-12);
const double pi = acos(-1);
typedef pair<int, int> P;
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EPS 1e-4
#define OUTPUT(i) (cout << (ll)i << endl)
#define ALL(a) ((a).begin(), (a).end())

bool operator<(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

ll arr[200010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);

    ll N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        if (i > 0)
            arr[i] += arr[i - 1];
    }

    ll ans = 10000000000;
    for (int i = 0; i < N - 1; ++i)
    {
        ans = min(ans, abs(arr[i] - (arr[N - 1] - arr[i])));
    }
    cout << ans << endl;
    return 0;
}
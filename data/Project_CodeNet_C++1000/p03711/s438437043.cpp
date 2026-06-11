#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

int main() {
    ll x, y;
    cin >> x >> y;

    int grp[12] = {1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};

    if (grp[x - 1] == grp[y - 1])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
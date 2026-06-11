#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    const bool ans = b - a == c - b;
    cout << (ans ? "YES" : "NO") << endl;
}

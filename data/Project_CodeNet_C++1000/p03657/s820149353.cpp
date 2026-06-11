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

    int a, b;
    cin >> a >> b;

    bool ans = false;

    ans |= a % 3 == 0;
    ans |= b % 3 == 0;
    ans |= (a + b) % 3 == 0;

    cout << (ans ? "Possible" : "Impossible") << endl;
}

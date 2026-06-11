#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    sort(p.begin(), p.end());

    int ans = p.back().first + p.back().second;

    cout << ans << endl;
    return 0;
}
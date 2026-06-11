#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll t, a, x = 1, y = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t >> a;
        ll u = (x - 1) / t + 1, v = (y - 1) / a + 1;
        x = t * max(u, v);
        y = a * max(u, v);
    }
    cout << x + y;
}

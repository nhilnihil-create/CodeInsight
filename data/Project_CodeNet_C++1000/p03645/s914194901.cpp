#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> count(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)swap(a, b);

        if (a == 1) count[b]++;
        if (b == n)count[a]++;
    }

    bool ret = false;
    for (int i = 0; i <= n; i++) {
        if (count[i] == 2)ret = true;
    }
    cout << (ret ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
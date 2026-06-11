#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> res(0, -1);
    while (n--) {
        int a, b; cin >> a >> b;
        res = max(res, {a, a + b});
    }
    cout << res.second << endl;
    return 0;
}

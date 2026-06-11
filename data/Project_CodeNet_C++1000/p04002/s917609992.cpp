#include <map>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int h, w, n; cin >> h >> w >> n;
    map<pair<int, int>, int> m;
    while (n--) {
        int x, y; cin >> x >> y; x--; y--;
        for (int i = max(0, x-2); i <= min(x, h-3); i++)
            for (int j = max(0, y-2); j <= min(y, w-3); j++)
                m[make_pair(i, j)]++;
    }
    int ans[10] = {};
    for (auto e : m) {
        ans[e.second]++;
    }
    long long ans0 = (long long)(h-2) * (w-2);
    for (int i = 1; i < 10; i++) ans0 -= ans[i];
    cout << ans0 << endl;
    for (int i = 1; i < 10; i++) cout << ans[i] << endl;
}

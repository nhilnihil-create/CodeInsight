#include <cstdio>
#include <functional>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<vector<int> > g(n);
    repeat (i, n - 1) {
        int x, y; scanf("%d%d", &x, &y); -- x; -- y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> grundy(n);
    function<int (int, int)> go = [&](int i, int parent) {
        int acc = 0;
        for (int j : g[i]) if (j != parent) {
            acc ^= go(j, i) + 1;
        }
        return acc;
    };
    int result = go(0, -1);
    printf("%s\n", result ? "Alice" : "Bob");
    return 0;
}

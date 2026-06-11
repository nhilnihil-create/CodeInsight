#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, p, cnt = 0, m;
    bool f = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (f) scanf("%d", &p);
        else scanf("%d", &m);
        if (i == p) {
            ++cnt;
            f = 0;
        } else f = 1;
    }
    printf("%d\n", cnt);
    return 0;
}

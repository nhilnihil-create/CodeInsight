#include <cstdio>
#include <algorithm>
using namespace std;

int n, cnt;
int a[200002];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            swap(a[i], a[i+1]);
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}
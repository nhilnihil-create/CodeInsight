#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> x(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    long long ans = 1, mod = 1e9 + 7, acum = 1;
    for (int i = 1; i < n; i++) {
        if (x[i] >= acum * 2 + 1) {
            acum++;
        } else {
            acum++;
            ans = ans * acum % mod;
            acum -= 2;
            i--;
        }
    }
    while (acum > 1) {
        ans = ans * acum % mod;
        acum--;
    }
    printf("%lld\n", ans);
	return 0;
}

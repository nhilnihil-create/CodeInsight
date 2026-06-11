#include <bits/stdc++.h>
using namespace std;

array<int, 100001> arr{};
int main() {
    int n, ans; ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        if (arr[arr[i]] == i) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
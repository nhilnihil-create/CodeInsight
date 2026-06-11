#include <bits/stdc++.h>
using namespace std;
#define N 100001
int t, a[N], n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    int add = 1, adds = 1;
    while (add < n && a[add + 1] >= add + 1) add++;
    while (adds < n && a[adds + 1] >= add) adds++;
    int ans = ((a[add] - add) & 1) || ((adds - add) & 1);
    puts(ans ? "First" : "Second");

    return 0;
}
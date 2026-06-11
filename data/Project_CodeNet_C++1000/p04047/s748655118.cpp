//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
int arr[105];

int main() {
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    n *= 2;
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int ans = 0;
    for (int i = 1; i < n; i += 2) ans += arr[i];
    printf("%d", ans);
  return 0;
}
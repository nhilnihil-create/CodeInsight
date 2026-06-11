#include <bits/stdc++.h>
using namespace std;

int n, a[100010], ans = 0;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        if(a[i] == i) {
            if(i == n) swap(a[i], a[i-1]), ans++;
            else swap(a[i], a[i+1]), ans++;
        }
    }
    printf("%d", ans);
}

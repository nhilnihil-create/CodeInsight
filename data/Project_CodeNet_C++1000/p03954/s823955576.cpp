#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N];
int b[N];
bool chk(int x) {
    for (int i = 0; i < n + n - 1; ++ i) {
        b[i] = a[i] >= x;
    }
    int mid = n - 1;
    for (int l = mid, r = mid; l > 0; -- l, ++ r) {
        if (b[l] == b[l - 1]) {
            return b[l];
        }
        if (b[r] == b[r + 1]) {
            return b[l];
        }
    }
    return b[0];
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n + n - 1; ++ i) scanf("%d", &a[i]);
    int lb = 1, rb = n + n - 1;
    while (lb < rb) {
        int md = (lb + rb + 1) >> 1;
        if (chk(md)) lb = md;
        else rb = md - 1;
    }
    printf("%d\n", lb);
    return 0;
}
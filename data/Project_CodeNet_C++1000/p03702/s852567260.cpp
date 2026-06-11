#include <bits/stdc++.h>

using i64 = long long;

i64 gcd(i64 a, i64 b) { return a ? gcd(b % a, a) : b; }

const int MAXN = 101000;

int n, a, b;
int arr[MAXN];

bool check(int x) {
    int s = 0;
    int y = x * b;
    for(int i = 0; i < n; ++i) {
        if(arr[i] <= y) continue;
        s += (arr[i] - y + a - 1) / a;
        if(s > x) return false;
    }
    return true;
}

int main() {
    std::scanf("%d%d%d", &n, &a, &b);
    a -= b;
    for(int i = 0; i < n; ++i)
        std::scanf("%d", &arr[i]);
    int l = 0, r = (*std::max_element(arr, arr + n) + b - 1) / b + 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if(!check(mid)) l = mid + 1;
        else r = mid;
    }
    std::printf("%d\n", l);
}
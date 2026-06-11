#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, k;
    cin >> n >> k;

    long ans = k * pow(k - 1, n - 1);
    cout << ans << endl;
}

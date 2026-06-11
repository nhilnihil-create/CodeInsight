#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    // 単調性が成り立つことを示す。
    // k - a[i] <= S < k となるSが存在するとすると、
    // a[j] > a[i] を満たす任意のa[j]について、k - a[j] <= S' < k が成り立つようなS'が存在することが示せる。
    // (Sに a[j]が含まれる場合と、a[j]が含まれない場合に分けると示せた。)

    // bitset高速化を付け加えてみた。

    int left = -1;
    int right = n;
    int mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        bitset<5010> dp;
        dp[0] = 1;

        rep(i, n) {
            if (i != mid) {
                dp |= (dp << a[i]);
            }
        }

        bool flag = 0;
        for (int j = max(0, k - a[mid]); j < k; j++) {
            flag |= dp[j];
        }
        if (flag) right = mid;
        else left = mid;
    }

    cout << left + 1 << endl;

    return 0;
}


    

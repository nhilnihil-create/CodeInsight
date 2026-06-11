#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
// #include <bits/stdc++.h>


using namespace std;
typedef long long li;
const li mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    li n;
    cin >> n;

    li ans = 1;
    li lastpos = -1;
    li cur_choices = n;
    for (int i = 0; i < n; ++i) {
        ans *= cur_choices - (n - 1 - i);
        ans %= mod;

        li x;
        cin >> x;
        if (lastpos <= x - 2) {
            lastpos += 2;
        } else {
            cur_choices -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}

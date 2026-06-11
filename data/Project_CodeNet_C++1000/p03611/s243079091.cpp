// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

constexpr int MAXA = 100000 - 1;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // valcount[i+1]: 操作するとiになる要素の数
    vector<int> valcount(MAXA + 1 + 2);

    for (int i = 0; i < n; i++) {
        valcount[a[i]]++;
        valcount[a[i] + 1]++;
        valcount[a[i] + 2]++;
    }

    const int ans = *max_element(valcount.begin(), valcount.end());
    cout << ans << endl;
}

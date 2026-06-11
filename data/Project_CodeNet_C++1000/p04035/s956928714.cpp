#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, l; cin >> n >> l;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    int idx = -1;
    for (int i = 1 ; i < n ; i++) {
        if (data[i - 1] + data[i] >= l)
            idx = i;
    }
    if (idx == -1) {
        cout << "Impossible\n";
        exit(0);
    }
    cout << "Possible\n";
    for (int i = 1 ; i < idx ; i++)
        cout << i << '\n';
    for (int i = n - 1 ; i > idx ; i--)
        cout << i << '\n';
    cout << idx << '\n';

}

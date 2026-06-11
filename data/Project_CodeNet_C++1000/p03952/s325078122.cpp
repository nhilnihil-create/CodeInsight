#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, x; cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (n == 2) {
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
        return 0;
    }
    vector<int> ans(2*n-1, -1);
    vector<bool> check(2*n, false);
    if (x == 2) {
        ans[n-2] = 3;
        ans[n-1] = 2;
        ans[n]   = 1;
        ans[n+1] = 4;
    }
    else {
        ans[n-2] = x-1;
        ans[n-1] = x;
        ans[n]   = x+1;
        ans[n+1] = x-2;
    }
    for (int i = 0; i < 2*n-1; i++) {
        if (ans[i] == -1) continue;
        check[ans[i]] = true;
    }
    int id = 1;
    for (int i = 0; i < 2*n-1; i++) {
        if (ans[i] != -1) continue;
        while (check[id]) id++;
        ans[i] = id; id++;
    }
    for (int i = 0; i < 2*n-1; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int l; cin >> l;
    vector<vector<int>> next(n, vector<int>(20, -1));
    for (int i = 0; i < n-1; i++) {
        int left = i; int right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (x[mid] - x[i] > l) right = mid;
            else left = mid;
        }
        next[i][0] = left;
    }
    for (int c = 0; c < 19; c++) {
        for (int i = 0; i < n; i++) {
            if (next[i][c] == -1) continue;
            next[i][c+1] = next[next[i][c]][c];
        }
    }
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        int left = 0; int right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            int curr = a;
            for (int i = 0; i < 20; i++) {
                if (mid & (1 << i)) {
                    curr = next[curr][i];
                }
                if (curr == -1) break;
            }
            if (curr == -1 || curr >= b) right = mid;
            else left = mid;
        }
        cout << right << endl;
    }
    return 0;
}
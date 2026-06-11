#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    int A[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> A[i][j];
    int ok = n, ng = 0;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        int idx[n] = {};
        bool removed[m+1] = {};
        while (*max_element(idx, idx+n) < m) {
            int cnt[m+1] = {};
            for (int i = 0; i < n; i++) {
                cnt[A[i][idx[i]]]++;
            }
            bool upd = false;
            for (int j = 1; j <= m; j++)
                if (cnt[j] > mid) removed[j] = true, upd = true;
            if (!upd) break;
            for (int i = 0; i < n; i++) {
                while (idx[i] < m && removed[A[i][idx[i]]]) idx[i]++;
            }  
        }
        if (*max_element(idx, idx+n) < m) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int i = 0;
    vector<vector<int>> grid(h, vector<int> (w));
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (a[i] == 0)
                i++;
                
            if (r & 1) {
                grid[r][w-c-1] = i;
                a[i]--;
            }
            else {
                grid[r][c] = i;
                a[i]--;
            }
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j;

    int h, w;
    cin >> h >> w;
    
    vector<vector<char>> a(h, vector<char>(w));
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<char>> b(h + 2, vector<char>(w + 2, '#'));
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            b[i + 1][j + 1] = a[i][j];
        }
    }
    
    for (i = 0; i < h + 2; i++) {
        for (j = 0; j < w + 2; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }
}
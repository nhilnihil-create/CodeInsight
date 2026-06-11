#include "bits/stdc++.h"
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    string s[x][y];
    bool T = false;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (s[i][j] == "snuke") {
                char c = j + 'A';
                printf("%c%d\n", c, i+1); 
                T = true; 
                break;
            }
        }
        if (T) break;
    }
}
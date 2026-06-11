#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int i, j, h, w;
    cin >> h >> w;
    char d[h+2][w+2];

    for (j=0; j<h+2; j++) {
        for (i=0; i<w+2; i++) {
            if (i==0 || j==0 || j==h+1 || i==w+1) {
                d[j][i] = '#';
                continue;
            }
            cin >> d[j][i];
        }
    }

    for (j=0; j<h+2; j++) {
        for (i=0; i<w+2; i++) {
            cout << d[j][i];
        }
        cout << endl;
    }
    cout << endl;
}
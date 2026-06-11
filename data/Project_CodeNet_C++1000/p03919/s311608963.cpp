#include <bits/stdc++.h>
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    char y = 'A';
    for (int i = 0 ; i < h; i++) {
        for (int j = 0; j < w; j++) {
            string su;
            cin >> su;
            if (su == "snuke") {
                i++;
                y += j;
                
                cout << y << i << endl;
                
            }
        }
    }
    
}


#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int h, w, d; cin >> h >> w >> d;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int a = (i+j) % (2*d) / d * 2 + ((i-j) % (2*d) + 2*d) % (2*d) / d;
            cout << "RYGB"[a];
        }
        cout << endl;
    }
}

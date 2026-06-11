#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int H, W; cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        vector<char> C(W, 'x');
        for (int j = 0; j < W; ++j) {
            cin >> C[j]; printf("%c", C[j]);
        }
        printf("\n");
        for (int j = 0; j < W; ++j) printf("%c", C[j]);
        printf("\n");
    }
}

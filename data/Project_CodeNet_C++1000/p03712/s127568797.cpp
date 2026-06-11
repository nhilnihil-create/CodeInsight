#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int H, W; cin >> H >> W;
    for (int i = 0; i < W + 2; ++i) printf("%c", '#');
    printf("\n");
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W + 2; ++j) {
            if (j == 0 || j == W + 1) printf("%c", '#');
            else {
                char a; cin >> a;
                printf("%c", a);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < W + 2; ++i) printf("%c", '#');
    printf("\n");
}

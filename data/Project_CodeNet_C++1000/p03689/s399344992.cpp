#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W, h, w, Swap = 0;
    cin >> H >> W >> h >> w;
    if(H % h == 0 && W % w == 0) {
        puts("No");
    } else {
        puts("Yes");
        int val = (h * w - 1) * 2333 + 1;
        for(int i = 1; i <= H; i++) {
            for(int j = 1; j <= W; j++) {
                if(i % h == 0 && j % w == 0)
                    printf("%d ", -val);
                else
                    printf("2333 ");
            }
            puts("");
        }
    }
    return 0;
}
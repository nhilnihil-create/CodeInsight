#include<bits/stdc++.h>
using namespace std;

int H, W, D;
char col[4] = { 'R', 'Y', 'G', 'B' };

int main() {
    scanf("%d %d %d", &H, &W, &D);

    int p;
    for(int i = 1;; i<<=1) {
        if(D % i) {
            p = i;
            break;
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            printf("%c", col[ ((i + j) % p) / (p/2) * 2 + (((i - j) % p + p) % p) / (p/2) ]);
        }
        printf("\n");
    }
}

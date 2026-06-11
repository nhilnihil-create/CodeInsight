#include <iostream>
#include <algorithm>
#include <cstdio>

int main() {
    int h, w, d;
    scanf("%d%d%d", &h, &w, &d);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int x = (i + j + w) / d, y = (i - j + w) / d;
            x &= 1, y &= 1;
            if (x && y) printf("Y");
            else if (x && !y) printf("B");
            else if (!x && y) printf("G");
            else printf("R"); 
        }
        printf("\n");
    }
}
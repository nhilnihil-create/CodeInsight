#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
        int h, w, d;
        scanf("%d%d%d", &h, &w, &d);
        for (int i = 0; i < h; i ++) {
                for (int j = 0; j < w; j ++) {
                        int x = (i + j) / d % 2;
                        int y = (h - 1 - (i - j)) / d % 2;
                        printf("%c", "RYGB"[x * 2 + y]);
                }
                puts("");
        }
        return 0;
}


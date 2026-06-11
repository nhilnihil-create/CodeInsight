#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int fact[65536];
int len;

void init() {
    int i = 1;
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < 65536; ++i) {
        fact[i] = fact[i-1] + i;
        if (fact[i] > (int)1e9) {
            //printf("%d\n", i); // 44721
            len = i+1;
            return ;
        }
    }
}

int main() {
    init();
    int X;
    while(scanf("%d", &X) != EOF) {
        if (X == 1) {
            printf("1\n");
            continue;
        }
        auto it = lower_bound(fact, fact+len, X);
        int x = distance(fact, it);
        printf("%d\n", x);
    }
}

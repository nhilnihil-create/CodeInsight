#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    if(a <= 0 && b >= 0) printf("Zero\n");
    else if(a < 0 && b < 0) {
        if((b - a + 1) % 2 == 0) printf("Positive\n");
        else printf("Negative\n");
    } else if(a > 0 && b > 0) printf("Positive\n");
}
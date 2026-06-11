#include <bits/stdc++.h>
using namespace std;

int a, b, ans;
char c;

int main() {
    scanf("%d %c %d", &a, &c, &b);
    if ( c == '+' ) ans = a + b;
    else ans = a - b;
    printf("%d\n", ans);
    return 0;
}

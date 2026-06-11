#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y, ans;
    scanf("%d", &x);
    y = ans =0;
    while (y < x) {
        ans++;
        y += ans;
    }
    printf("%d\n", ans);
    return 0;
}
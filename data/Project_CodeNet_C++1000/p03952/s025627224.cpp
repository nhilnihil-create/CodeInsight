#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    if (x == (2 * n - 1) || x == 1){
        printf("No\n");
    }
    else {
        printf("Yes\n");
        for (int i = 1, j = 2; i <= 2 * n - 1; i++) {
            if (i == n - 1)
                printf("1\n");
            else if (i == n)
                printf("%d\n", x);
            else if (i == n + 1)
                printf("%d\n", 2 * n - 1);
            else {
                if (j == x) j++;
                printf("%d\n", j);
                j++;
            }
        }
    }
}

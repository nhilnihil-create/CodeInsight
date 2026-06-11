#include<iostream>
using namespace std;

int main() {
    int w, h, n;
    scanf("%d %d %d", &w, &h, &n);

    int x, y, a;
    int max_x = w, min_x = 0, max_y = h, min_y = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &a);
        if (a == 1) min_x = max(min_x, x);
        else if (a == 2) max_x = min(max_x, x);
        else if (a == 3) min_y = max(min_y, y);
        else if (a == 4) max_y = min(max_y, y);
    }

    int nw = max(max_x - min_x, 0);
    int nh = max(max_y - min_y, 0);
    printf("%d\n", nw * nh);
}
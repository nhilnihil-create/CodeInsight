#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int main() {
    int n , m , d ;
    cin >> n >> m >> d;
    if (d % 2 == 1) {
        for (int i = 0 ; i < n ; ++ i) {
            for (int j = 0 ; j < m ; ++ j) {
                putchar("RG"[(i + j) & 1]);
            }
            puts("");
        }
    } else {
        int l = d + d;
        for (int i = 0 ; i < n ; ++ i) {
            for (int j = 0 ; j < m ; ++ j) {
                int p = (i + j) % l;
                int w = (i - j % l + l) % l;
                putchar("RGBY"[(p < d) * 2 + (w < d)]);
            }
            puts("");
        }
    }


}

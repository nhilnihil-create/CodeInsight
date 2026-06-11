#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;

    int64_t m = n + 1; // m >= 2
    int s[200], k = 0;
    int i0 = 100, i1 = 100;
    int64_t x = 1;
    int j;
    for (j = 63; j >= 0; j--) if (m >> j & 1) break;
    for (j--; j >= 0; j--) {
        x *= 2;
        s[i1++] = k++;
        if (m >> j & 1) {
            x += 1;
            s[--i0] = k++;
        }
    }
    if (n != x - 1) throw;

    cout << (i1 - i0) * 2 << '\n';
    for (int i = 0; i < i1 - i0; i++) {
        cout << i + 1 << " ";
    }
    for (int i = i0; i < i1; i++) {
        cout << s[i] + 1 << " \n"[i == i1 - 1];
    }

    return 0;
}
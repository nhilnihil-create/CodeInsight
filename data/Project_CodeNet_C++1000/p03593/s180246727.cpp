#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int H, W;
    cin >> H >> W;
    int a[26] = {};
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (auto c: S) {
            a[c-'a']++;
        }
    }
    int b[5] = {};
    for (int i = W; i > 0; i-=2) {
        for (int j = H; j > 0; j-=2) {
            b[min(2, i)*min(2, j)]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] % 2 == 1 && b[1]) {
            a[i]--;
            b[1]--;
        }
    }
    for (int i = 0; i < 26; i++) {
        int c = min(a[i]/4, b[4]);
        a[i] -= c*4;
        b[4] -= c;
    }
    for (int i = 0; i < 26; i++) {
        int c = min(a[i]/2, b[2]);
        a[i] -= c*2;
        b[2] -= c;
    }
    if (b[1] == 0 && b[2] == 0 && b[4] == 0) {
        puts("Yes");
    }
    else {
        puts("No");
    }
}
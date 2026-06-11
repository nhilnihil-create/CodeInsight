#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    pair<int, int> ans = make_pair(A * 100, 0);
    float con = 0.0;
    int a = 0;
    while (1) {
        int an = A * a * 100;
        if (an > F)
            break;
        int b = 0;
        while (1) {
            int bn = B * b * 100;
            if (an + bn > F)
                break;
            int c = 0;
            while (1) {
                int cn = c * C;
                if (an + bn + cn > F)
                    break;
                int d = 0;
                while (1) {
                    int dn = d * D;
                    if (an + bn + cn + dn > F)
                        break;
                    if (cn + dn <= (an + bn) / 100 * E && con < (float)(cn + dn) / (float)(an+bn+cn+dn)){
                        ans = make_pair(an + bn + cn + dn, cn + dn);
                        con = (float)(cn + dn) / (float)(an + bn + cn + dn);
                    }
                    ++d;
                }
                ++c;
            }
            ++b;
        }
        ++a;
    }
    cout << ans.first << " " << ans.second << "\n";
}
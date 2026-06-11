#include <iostream>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int fa = a, fb = b, fc = c;
    int cnt = 0;
    while (a%2 + b%2 + c%2 == 0) {
        int na, nb, nc;
        na = b/2 + c/2;
        nb = c/2 + a/2;
        nc = a/2 + b/2;
        if (na == fa && nb == fb && nc == fc) {
            cout << -1 << endl;
            return 0;
        }
        a = na; b = nb; c = nc;
        cnt++;
    }
    cout << cnt << endl;
}
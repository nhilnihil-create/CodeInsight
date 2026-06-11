#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a,b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int sb, wb;
    sb = c; wb = f - sb + 1;
    for (int i = 0; i <= f; i += a * 100) {
        for (int j = 0; i + j <= f; j += b * 100) {
            int wat = i + j;
            int maxsug = min(e * (wat / 100), f - wat);
            for (int k = 0; k <= maxsug; k+=d) {
                for (int q =0; k + q <= maxsug; q += c) {
                    int sug = q + k;
                    if (sug * (sb + wb) > sb * (sug + wat)) {
                        sb = sug;
                        wb = wat;
                    }
                }
            }
        }
    }
    if (sb == c && wb == f-sb+1) {
        sb = 0;
        wb = a*100;
    }
    cout << wb + sb << " " << sb;


}

int main() {

	solve();
    return 0;
}

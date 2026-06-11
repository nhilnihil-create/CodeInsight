#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d, e, f, g;
    while (cin >> a >> b >> c >> d >> e >> f >> g) {
        long long res = 0;
        long long m = min(a, min(d, e));
        for (long long i = max(m-2, 0LL); i <= m; ++i) {
            long long tmp = i * 3;
            long long na = a - i, nd = d - i, ne = e - i;
            tmp += na/2 * 2;
            tmp += nd/2 * 2;
            tmp += ne/2 * 2;
            res = max(res, tmp);
        }
        cout << res + b << endl;
    }
}

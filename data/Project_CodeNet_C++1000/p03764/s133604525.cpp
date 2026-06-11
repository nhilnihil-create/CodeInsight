#include <iostream>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    const long long M = (long long)1e9 + 7;
    long long xsum = 0, ysum = 0, xans = 0, yans = 0;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        xans = (xans + x * i - xsum) % M;
        xsum = (xsum + x) % M;
    }
    for (int i = 0; i < m; i++) {
        long long x; cin >> x;
        yans = (yans + x * i - ysum) % M;
        ysum = (ysum + x) % M;
    }
    cout << xans * yans % M << endl;
}

#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = -1;
    for(int i = 0; i < (1 << n); i++) {
        long long cost = 0;
        long long hmax = 0;
        int color = 0;
        for(int j = 0; j < n; j++) {
            if(1 & (i >> j)) {
                color++;
                if(a[j] <= hmax) {
                    hmax++;
                    cost += hmax - a[j];
                } else {
                    hmax = a[j];
                }
            } else {
                if(a[j] > hmax) {
                    color++;
                    hmax = a[j];
                }
            }
        }
        if(color >= k) {
            if(ans == -1) {
                ans = cost;
            } else {
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
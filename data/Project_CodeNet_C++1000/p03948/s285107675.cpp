#include <iostream>
using namespace std;

int main() {
    int n, t, result = 0;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int best = 0, worst = a[0];
    for (int i = 0; i < n; ++i) {
        best = max(best, a[i] - worst);
        worst = min(worst, a[i]);
    }
    worst = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] - worst == best) {
            ++result;
        }
        worst = min(worst, a[i]);
    }
    cout << result;
    return 0;
}

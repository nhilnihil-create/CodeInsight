#include <iostream>
using namespace std;

int n, mn, mx, mn_count, mx_count;
int a;

int main() {
    mn_count = mx_count = 0;
    mn = 2000 * 1000 * 1000;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > mx) {
            mx = a;
            mx_count = 0;
        }
        if (a < mn) {
            mn = a;
            mn_count = 0;
        }
        if (a == mn)
            mn_count++;
        if (a == mx)
            mx_count++;
    }
    if (mx - mn > 1)
        return cout << "No" << '\n', 0;
    if (mx - mn == 1)
        if (mx <= mn_count || mx > mn_count + mx_count / 2)
            return cout << "No" << '\n', 0;
    if (mn == mx) 
        if (mx > n / 2 && mx != n - 1) 
            return cout << "No" << '\n', 0;
    cout << "Yes" << '\n';
    return 0;
}


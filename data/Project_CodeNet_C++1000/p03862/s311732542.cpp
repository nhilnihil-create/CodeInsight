#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    // int a[n];
    // for (int i = 0; i < n; ++i) {
    //     cin >> a[i];
    // }
    // int count = 0;
    // if (a[0] > x) {
    //     a[0] = x;
    //     count += a[0];
    // }

    long long int count = 0;
    int last = -1;
    int curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (last >= 0) {
            if (last + curr > x) {
                count += last + curr - x;
                curr = x - last;
            }
        } else {
            if (curr > x) {
                count += curr - x;
                curr = x;
            }
        }
        // cout << curr << '\t';
        last = curr;
    }
    cout << count << endl;
}
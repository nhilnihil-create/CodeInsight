#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unsigned long long int total;
    sort(a.begin(), a.end());
    int ind;
    bool have_case = true;
    if (n % 2 == 1) {
        if (a[0] == 0) {
            ind = 1;
            while (ind < n - 1) {
                if (a[ind] != a[ind - 1] + 2 || a[ind + 1] != a[ind - 1] + 2) {
                    have_case = false;
                    break;
                }
                ind += 2;
            }
        } else
            have_case = false;
    } else {
        if (a[0] == 1 && a[1] == 1) {
            ind = 2;
            while (ind < n - 1) {
                if (a[ind] != a[ind - 1] + 2 || a[ind + 1] != a[ind - 1] + 2) {
                    have_case = false;
                    break;
                }
                ind += 2;
            }
        } else
            have_case = false;
    }

    if (have_case) {
        int n_div = pow(10, 9) + 7;
        total = 1;
        for (int i = 0; i < n / 2; i++) {
            total *= 2;
            total %= n_div;
        }
    } else {
        total = 0;
    }
    cout << total << endl;
    return 0;
}
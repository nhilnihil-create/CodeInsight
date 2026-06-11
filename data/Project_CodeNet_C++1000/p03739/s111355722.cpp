#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    vector<long long> a(n);
    for(unsigned long long i = 0; i < n; ++i) cin >> a[i];
    unsigned long long op_1 = 0;
    long long sum = 0;
    for (unsigned long long i = 0; i < n; ++i) {
        sum += a[i];
        if (i % 2 == 0) {
            while (sum <= 0) {
                ++sum;
                ++op_1;
            }
        }
        else {
            while (sum >= 0) {
                --sum;
                ++op_1;
            }
        }
    }
    unsigned long long op_2 = 0;
    sum = 0;
    for (unsigned long long i = 0; i < n; ++i) {
        sum += a[i];
        if (i % 2 == 0) {
            while (sum >= 0) {
                --sum;
                ++op_2;
            }
        }
        else {
            while (sum <= 0) {
                ++sum;
                ++op_2;
            }
        }
    }
    cout << min(op_1, op_2) << endl;
    return EXIT_SUCCESS;
}
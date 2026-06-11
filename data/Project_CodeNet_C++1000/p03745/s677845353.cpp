#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    vector<unsigned long long> a(n);
    for (size_t i = 0; i < n; ++i) cin >> a[i];
    bool isGE = false;
    bool isLE = false;
    unsigned long long counter = 1;
    for (size_t i = 0; i < n - 1; ++i) {
        if (!isGE && !isLE) {
            if (a[i] > a[i + 1]) isLE = true;
            else if (a[i] < a[i + 1]) isGE = true;
        }
        else if (isGE) {
            if (a[i] <= a[i + 1]) continue;
            else {
                isGE = false;
                ++counter;
            }
        }
        else if (isLE) {
            if (a[i] >= a[i + 1]) continue;
            else {
                isLE = false;
                ++counter;
            }
        }
    }
    cout << counter << endl;
    return EXIT_SUCCESS;
}
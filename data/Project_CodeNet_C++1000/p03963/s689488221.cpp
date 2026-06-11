#include <iostream>

using namespace std;

int main() {
    unsigned long long n, k;
    cin >> n >> k;
    unsigned long long variation = k;
    for (unsigned long long i = 0; i < n - 1; ++i) {
        variation *= (k - 1);
    }
    cout << variation << endl;
    return EXIT_SUCCESS;
}
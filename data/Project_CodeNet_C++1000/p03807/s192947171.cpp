#include <iostream>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    size_t num_odd = 0;
    for (unsigned long long i = 0; i < n; ++i) {
        unsigned long long a;
        cin >> a;
        if (a % 2 != 0) ++num_odd;
    }
    cout << (num_odd % 2 == 0 ? "YES" : "NO") << endl;
    return EXIT_SUCCESS;
}
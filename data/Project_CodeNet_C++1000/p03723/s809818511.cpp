#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    if (a == b && a == c) {
        cout << (a % 2 == 0 ? -1 : 0) << endl;
    }
    else {
        unsigned long long count = 0;
        while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
            ++count;
            unsigned long long tmp_a = (b + c) / 2;
            unsigned long long tmp_b = (a + c) / 2;
            unsigned long long tmp_c = (a + b) / 2;
            a = tmp_a;
            b = tmp_b;
            c = tmp_c;
        }
        cout << count << endl;
    }
    return EXIT_SUCCESS;
}
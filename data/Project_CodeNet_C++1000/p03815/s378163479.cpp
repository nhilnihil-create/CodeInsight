#include <iostream>
using namespace std;

int main() {
    long int x;
    long int n_time = 0;
    cin >> x;
    n_time = (x / 11) * 2;
    if (x % 11 == 0) n_time += 0;
    else if (x % 11 <= 6)
        n_time += 1;
    else
        n_time += 2;
    cout << n_time << endl;
    return 0;
}
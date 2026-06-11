#include <cmath>
#include <iostream>
using namespace std;
int main() {
    long long n, k; cin >> n >> k;
    cout << (abs(n-k) <= 1 ? "Brown" : "Alice") << endl;
}

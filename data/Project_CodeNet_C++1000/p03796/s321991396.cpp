#include <iostream>
using namespace std;
int main() {
    long n, power = 1;
    cin >> n;
    for (long i = 1; i < n+1; ++i)power = power % 1000000007 * i % 1000000007;
    cout << power << endl;
}

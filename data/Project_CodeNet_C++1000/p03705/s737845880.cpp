#include <iostream>
using namespace std;
int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long result;
    if (n == 0 || a > b) {
        result = 0;
    } else if (n == 1) {
        if (a != b) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        result = (n-2) * (b-a) + 1;
    } 
    cout << result << endl;
}
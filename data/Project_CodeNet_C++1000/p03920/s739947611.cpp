#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    int k = 1;
    while(k * (k + 1) / 2 <= n) {
        ++k;
    }
    --k;
    int dif = n - k * (k + 1) / 2;
    for(int i = 1; i <= k - dif; ++i) {
        cout << i << "\n";
    }
    for(int i = k - dif + 1; i <= k; ++i) {
        cout << i + 1 << "\n";
    }
    return 0;
}

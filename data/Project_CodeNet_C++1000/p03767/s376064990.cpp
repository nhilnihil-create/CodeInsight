#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> strength(3 * n);
    for (size_t i = 0; i < 3 * n; ++i) cin >> strength[i];
    sort(strength.begin(), strength.end(), greater<int>());
    unsigned long long sum = 0;
    for(size_t i = 0, j = 1; i < n; j += 2, ++i) {
        sum += strength[j];
    }
    cout << sum << endl;
    return EXIT_SUCCESS;
}
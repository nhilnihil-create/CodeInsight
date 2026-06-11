#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sticks(n);
    for (size_t i = 0; i < n; ++i) cin >> sticks[i];
    sort(sticks.begin(), sticks.end(), greater<int>());
    cout << accumulate(sticks.begin(), sticks.begin() + k, 0) << endl;
    return EXIT_SUCCESS;
}
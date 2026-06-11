#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int min_value = INT_MAX;
    for (int i = v[0]; i <= v[n - 1]; ++i) {
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            temp += ((v[j] - i) * (v[j] - i));
        }
        min_value = min(temp, min_value);
    }
    cout << min_value << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t, m = 0;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a.at(i);
    for (int i = n - 1; i >= 0; --i) {
        m = max(m, a.at(i));
        a.at(i) = m - a.at(i);
    }
    cout << count(a.begin(), a.end(), *max_element(a.begin(), a.end())) << endl;
    return 0;
}

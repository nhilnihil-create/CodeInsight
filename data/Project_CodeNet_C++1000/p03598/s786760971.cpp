#include <iostream>
#include <vector>

using namespace  std;
int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] > k / 2) {
            sum += 2*(k - x[i]);
        } else {
            sum += 2*(x[i]);
        }
    }
    cout << sum << endl;
}


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> n_num(*max_element(a.begin(), a.end()), 0);
    int n_even = 0, n_odd = 0;
    for (int i = 0; i < n; i++) {
        n_num[a[i] - 1]++;
    }
    for (int i = 0; i < n_num.size(); i++) {
        if (n_num[i] % 2 == 0) {
            if (n_num[i] != 0) n_even++;
        } else
            n_odd++;
    }
    cout << n_odd + n_even - (n_even % 2) << endl;
    return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<unsigned long long int> v(3, 0);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            cout << 0 << endl; return 0;
        }
    }
    sort(v.begin(), v.end());
    cout << v[0] * v[1] << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int count_odd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1) {
            count_odd++;
        }
    }
    if (count_odd % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}


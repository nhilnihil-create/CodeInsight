
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (n == 2) {
        cout << 1 << endl << 2 << endl << 3 << endl;
        return 0;
    }
    vector<int> res(2 * n, 0);
    if (x > 2) {
        res[n] = x, res[n - 1] = x - 2, res[n + 1] = x + 1, res[n + 2] = x - 1;
    } else {
        res[n] = x, res[n - 1] = x + 2, res[n + 1] = x - 1, res[n + 2] = x + 1;
    }
    int index = 1;
    for (int i = 1; i <= 2 * n - 1; i++) {
        int flag = 1;
        for (int j = n - 1; j <= n + 2; j++) {
            if (res[j] == i) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) continue;
        while (index <= 2 * n - 1 && res[index] != 0) {
            index++;
        }
        if (index <= 2 * n - 1)
        res[index++] = i;
    }
    for (int i = 1; i <= 2 * n - 1; i++) {
        cout << res[i] << endl;
    }
}

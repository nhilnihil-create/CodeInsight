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
    int n;
    cin >> n;
    int a4 = 0, a2 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 4 == 0) {
            a4++;
        } else if (a % 2 == 0) {
            a2++;
        }
    }
    int a1 = n - a4 - a2;
    int flag = 1;
    if (a2 > 0) {
        if (a4 < a1) flag = 0;
    } else {
        if (a4 < a1 - 1) flag = 0;
    }
    if (flag == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}



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
    string s;
    cin >> s;
    int n = s.size() / 2 - 1;
    int res = 0;
    for (int i = n; i > 0; i--) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (s[j] != s[j + i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) res = max(i * 2, res);
    }   
    cout << res << endl;
}

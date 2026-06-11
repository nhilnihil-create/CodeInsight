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
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int last = 0;
    long long int res = 0;
    int index = 0;
    if (s1[0] == s2[0]) {
        last = 1;
        res = 3;
        index = 1;
    } else {
        last = 2;
        res = 6;
        index = 2;
    }
    while (index < n) {
        if (s1[index] == s2[index]) {
            if (last == 1) {
                res *= 2;
            } else {
                res *= 1;
            }
            last = 1;
            index++;
        } else {
            if (last == 1) {
                res *= 2;
            } else {
                res *= 3;
            }
            last = 2;
            index += 2;
        }
        res %= mod;
    }
    cout << res << endl;
}

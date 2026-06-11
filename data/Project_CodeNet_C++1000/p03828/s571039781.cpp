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
    unordered_map<int, int> um;
    for (int i = 2; i <= n; i++) {
        int num = i;
        for (int j = 2; j * j <= num; j++) {
            while (num % j == 0) {
                num /= j;
                um[j]++;
            }
        }
        if (num > 1) {
            um[num]++;
        }
    }
    long long int res = 1;
    const int mod = 1e9 + 7;
    for (auto p : um) {
        res = res * (p.second + 1) % mod;
    }
    cout << res << endl;
}



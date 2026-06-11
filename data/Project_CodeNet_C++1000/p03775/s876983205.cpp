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
    long long int n;
    cin >> n;
    long long int res = 11;
    for (long long int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            long long int l = max(to_string(i).size(), to_string(n / i).size());
            res = min(l, res);
        }
    }
    cout << res << endl;
}



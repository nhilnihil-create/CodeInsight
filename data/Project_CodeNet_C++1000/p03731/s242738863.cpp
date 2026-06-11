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
    long long int n, t;
    cin >> n >> t;
    long long int res = 0;
    long long int last = 0;
    for (int i = 0; i < n; i++) {
        long long int tt;
        cin >> tt;
        res += min(t, tt + t - last);
        last = tt + t;
    }
    cout << res << endl;
}



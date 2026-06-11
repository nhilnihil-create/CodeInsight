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
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res += min(x, abs(x - k)) * 2;
    }
    cout << res << endl;
}



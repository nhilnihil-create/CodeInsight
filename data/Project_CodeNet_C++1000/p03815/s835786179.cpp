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
    long long int x;
    cin >> x;
    long long int res = 0;
    res += x / 11 * 2;
    x %= 11;
    if (x > 6) {
        res += 2;
    } else if (x > 0) {
        res += 1;
    } 
    cout << res << endl;
}



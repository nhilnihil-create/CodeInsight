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
    vector<long long int> fac(1, 1);
    int n;
    cin >> n;
    const int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        fac.push_back(fac.back() * i % mod);
    }
    cout << fac.back() << endl;
}

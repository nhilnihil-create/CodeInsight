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
    long long int a, b, c;
    cin >> a >> b >> c;
    cout << min(b % 2 * a * c, min(a % 2 * b * c, c % 2 * a * b)) << endl;
}



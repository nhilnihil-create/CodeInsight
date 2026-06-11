
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
    cout << "ABC";
    if (n < 10)
        cout << "00";
    else if (n < 100)
        cout << "0";
    cout << n << endl;
}

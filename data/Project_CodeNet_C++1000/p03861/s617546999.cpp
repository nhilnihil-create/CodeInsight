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
    long long int a, b, x;
    cin >> a >> b >> x;
    cout << b / x + 1 - a / x - 1 + (a % x == 0 ? 1 : 0) << endl;   
}



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
    long long int s, c;
    cin >> s >> c;
    cout << min(s, c / 2) + max((long long int)0, c - s * 2) / 4 << endl;
}

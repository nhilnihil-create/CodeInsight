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
    string s;
    cin >> s;
    int i1 = 0, i2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            i1 = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            i2 = i;
            break;
        }
    }
    cout << i2 - i1 + 1 << endl;
}



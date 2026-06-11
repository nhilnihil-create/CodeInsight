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
    string s;
    cin >> s;
    int res = 0;
    int c = 0;
    for (auto ss : s) {
        if (ss == 'I') {
            c++; 
        } else {
            c--;
        }
        res = max(res, c);
    }
    cout << res << endl;
}



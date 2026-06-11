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
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size()) {
        cout << "GREATER" << endl;
    } else if (a.size() < b.size()) {
        cout << "LESS" << endl;
    } else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > b[i]) {
                cout << "GREATER" << endl;
                return 0;
            }
            if (a[i] < b[i]) {
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
}

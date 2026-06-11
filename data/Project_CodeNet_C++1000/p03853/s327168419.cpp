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
    int h, w;
    cin >> h >> w;
    vector<string> vs;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    for (int i = 1; i <= 2 * h; i++) {
        cout << vs[(i + 1) / 2 - 1] << endl;
    }
}



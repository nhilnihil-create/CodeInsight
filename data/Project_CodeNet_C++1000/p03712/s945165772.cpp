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
    cout << string(w + 2, '#') << endl;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        cout << string(1, '#') << s << string(1, '#') << endl;

    }
    cout << string(w + 2, '#') << endl;

}

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
    vector<vector<int>> res(h, vector<int>(w, 0));
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int index = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[index] == 0) index++;
            res[i][j] = index + 1;
            v[index]--;
        }
        if (i % 2 == 1) reverse(res[i].begin(), res[i].end());
        for (auto num : res[i]) {
            cout << num << " ";
        }
        cout << endl;
    }
}

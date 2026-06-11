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
    int n, m;
    cin >> n >> m;
    vector<int> v1(n + 1, 1), v2(n + 1, 0);
    v2[1] = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (v2[a] == 1) {
            v2[b] = 1;
        }
        if (v1[a] == 1) {
            v2[a] = 0;
        } 
        v1[a]--;
        v1[b]++;
    }
    cout << accumulate(v2.begin(), v2.end(), 0) << endl;
}



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
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<vector<int>> v1(401, vector<int>(401, 0x3f3f3f3f));
    vector<vector<int>> v2(401, vector<int>(401, 0x3f3f3f3f));
    v1[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v2 = v1;
        for (int x = 0; x + a <= 400; x++) {
            for (int y = 0; y + b <= 400; y++) {
                v2[x + a][y + b] = min(v2[x + a][y + b], v1[x][y] + c);
            }
        }
        v1 = v2;
    }
    int res = 0x3f3f3f3f;
    for (int i = 1; i * ma <= 400 && i * mb <= 400; i++) {
        res = min(res, v1[i * ma][i * mb]);
    }
    cout << (res == 0x3f3f3f3f ? -1 : res) << endl;
}

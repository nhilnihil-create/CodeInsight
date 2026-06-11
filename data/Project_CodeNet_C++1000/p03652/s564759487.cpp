#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m], index[n] = {}, count[m] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
        count[a[i][0]]++;
    }
    vector<bool> alive(m, true);
    int current = distance(count, max_element(count, count + m)), result = count[current];
    for (int i = 1; i < m; i++) {
        alive[current] = false;
        for (int j = 0; j < n; j++) {
            count[a[j][index[j]]]--;
            while (!alive[a[j][index[j]]]) {
                index[j]++;
            }
            count[a[j][index[j]]]++;
            if (count[current] < count[a[j][index[j]]]) {
                current = a[j][index[j]];
            }
        }
        result = min(result, count[current]);
    }
    cout << result;
    return 0;
}

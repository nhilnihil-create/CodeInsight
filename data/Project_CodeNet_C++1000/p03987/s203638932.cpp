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
    vector<int> v(n, 0), v1(n, 0), v2(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v1[i] = i;
        v2[i] = i;
    }
    vector<int> s;
    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            s.push_back(i);
        } else {
            while (s.size() > 0) {
                int index = s.back();
                if (v[index] > v[i]) {
                    v1[index] = i - 1;
                    s.pop_back();
                } else {
                    break;
                }
            }
            s.push_back(i);
        }
    }
    while (s.size() > 0) {
        v1[s.back()] = n - 1;
        s.pop_back();
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s.size() == 0) {
            s.push_back(i);
        } else {
            while (s.size() > 0) {
                int index = s.back();
                if (v[index] > v[i]) {
                    v2[index] = i + 1;
                    s.pop_back();
                } else {
                    break;
                }
            }
            s.push_back(i);
        }
    }
    while (s.size() > 0) {
        v2[s.back()] = 0;
        s.pop_back();
    }
    long long int res = 0;
    for (int i = 0; i < n; i++) {
        res += (long long int)1 * (v1[i] - i + 1) * (i - v2[i] + 1) * v[i];
    }
    cout << res << endl;
}



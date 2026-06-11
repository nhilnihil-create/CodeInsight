#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
#include <array>
#include <iomanip>


using namespace std;
constexpr int kMaxN = 30000;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    std::vector<int> perm(n), answer(n);
    for (auto& el : perm) {
        cin >> el;

        el--;
    }
    for (int i = 0; i < n; i++) {
        cout << (i + 1) * kMaxN << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        answer[perm[i]] = (n - perm[i]) * kMaxN + i + 1;
    }
    for (auto& el : answer) {
        cout << el << " ";
    }
    cout << endl;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    int odd = 0;
    for (int ai: a) if (ai & 1) odd++;
    cout << (odd % 2 == 0 ? "YES" : "NO") << endl;
    return 0;
}

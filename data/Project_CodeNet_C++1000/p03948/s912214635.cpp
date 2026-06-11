#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, T; cin >> N >> T;
    vector<int> a(N);
    for (int& ai : a) cin >> ai;
    vector<int> rangeMax(N);
    rangeMax[N - 1] = a[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        rangeMax[i] = max(rangeMax[i + 1], a[i]);
    }
    map<int, int> cnt;
    for (int i = 0; i < N - 1; i++) {
        cnt[rangeMax[i + 1] - a[i]]++;
    }
    cout << (--cnt.end())->second << endl;
    return 0;
}
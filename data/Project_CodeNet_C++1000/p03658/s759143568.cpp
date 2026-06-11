#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    uint N, K;
    cin >> N >> K;

    vector<int> l(N, 0);
    for (auto &x: l) cin >> x;
    sort(l.begin(), l.end(), greater<int>());

    int sum = 0;
    for (size_t i=0; i<K; ++i) sum += l[i];
    cout << sum << endl;
}

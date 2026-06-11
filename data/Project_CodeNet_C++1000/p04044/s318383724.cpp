#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    uint N, L;
    cin >> N >> L;

    vector<string> S(N, string(L, 'a'));
    for (auto &x: S) cin >> x;

    sort(S.begin(), S.end());
    string T;
    for (auto &x: S) T = T + x;
    cout << T << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using llong = long long;

int main() {
    uint N;
    cin >> N;
    vector<int> a(3*N, 0);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    size_t first = N;
    llong strength = 0;
    for (size_t i=first; i<a.size(); i+=2) {
        strength += a[i];
    }
    cout << strength << endl;
}

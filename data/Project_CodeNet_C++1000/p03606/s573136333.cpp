#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> l.at(i) >> r.at(i);
        ans += r.at(i) - l.at(i) + 1;
    }
    cout << ans << endl;
}
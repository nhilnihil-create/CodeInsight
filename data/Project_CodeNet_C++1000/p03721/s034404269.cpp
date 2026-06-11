#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int n, k;
    cin >> n >> k;
    vector<pair<Int, Int> > a(n);
    for (Int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    Int sum = 0;
    for (Int i = 0; i < n; ++i) {
        if (sum + a[i].second >= k) {
            cout << a[i].first << endl;
            break;
        } else {
            sum += a[i].second;
        }
    }
    return 0;
}


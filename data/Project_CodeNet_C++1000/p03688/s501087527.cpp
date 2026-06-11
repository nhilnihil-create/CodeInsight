#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) cin >> e;
    int lo = *min_element(a.begin(), a.end());
    int hi = *max_element(a.begin(), a.end());
   
    if (hi - lo > 1) return false;

    if (hi == lo) return hi == n-1 || hi <= n/2;
    

    int locnt = count(a.begin(), a.end(), lo);
    if (locnt > hi-1) return false;
    int r = hi - locnt;
    return (n-locnt)/r >= 2;
}

int main() {
    if (solve()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

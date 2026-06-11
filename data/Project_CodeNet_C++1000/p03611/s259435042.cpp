#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int ai;
        cin >> ai;
        ++a[ai];
    }
    int maxp = 0;
    for (int i=1; i<100000-1; ++i) {
        int t;
        t = a[i-1] + a[i] + a[i+1];
        if (t > maxp)
            maxp = t;
    }
    cout << maxp;

}

int main() {

	solve();
    return 0;
}

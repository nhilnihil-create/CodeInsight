#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, t, tmp = 0;   cin >> k >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        tmp = max(tmp, a[i]);
    }

    cout << max(tmp-1-(k-tmp), 0) << endl;
    return 0;
}
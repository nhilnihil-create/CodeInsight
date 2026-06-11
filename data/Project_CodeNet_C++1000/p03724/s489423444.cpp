#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;  cin >> n >> m;
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;   cin >> a >> b;
        cnt[a-1]++;
        cnt[b-1]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] % 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
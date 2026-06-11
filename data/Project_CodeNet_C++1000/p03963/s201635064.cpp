#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans{1};
    ans = ans * k;
    for (int i = 0; i < n - 1; i++) {
        ans = ans * (k - 1);
    }
    cout << ans << endl;
    return 0;
}

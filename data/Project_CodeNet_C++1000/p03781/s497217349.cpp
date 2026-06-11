#include <iostream>
using namespace std;

int main() {
    int x; cin >> x;
    int ans = 0;
    int sum = 0;
    while (sum < x) {
        ans++;
        sum += ans;
    }
    cout << ans << endl;
}
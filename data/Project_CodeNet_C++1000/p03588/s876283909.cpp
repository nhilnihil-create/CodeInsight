#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int max_a = 0, ans = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a > max_a) {
            max_a = a;
            ans = a + b;
        }
    }
    cout << ans << '\n';
}
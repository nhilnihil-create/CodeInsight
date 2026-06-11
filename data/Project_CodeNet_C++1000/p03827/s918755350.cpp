#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x = 0; cin >> n;
    char s[101]; cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        x += (s[i] == 'I') * 2 - 1;
        ans = max(ans, x);
    }

    cout << ans << endl;
}


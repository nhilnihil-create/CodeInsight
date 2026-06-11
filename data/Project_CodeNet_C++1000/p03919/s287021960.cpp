#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            string s;
            cin >> s;
            if(s[0] == 's' && s[1] == 'n' && s[2] == 'u' && s[3] == 'k' && s[4] == 'e') {
                cout << (char)('A' + j - 1) << i << "\n";
            }
        }
    }
    return 0;
}

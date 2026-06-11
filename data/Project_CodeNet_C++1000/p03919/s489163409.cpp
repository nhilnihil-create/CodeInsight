#include <iostream>
#include <vector>

using namespace std;

int main () {
    
    int h, w;
    cin >> h >> w;

    string ans;
    vector<vector<string>> s(h, vector<string>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s[i][j];
            if (s[i][j] == "snuke") {
                ans = (char)('A' + j) + to_string(i + 1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
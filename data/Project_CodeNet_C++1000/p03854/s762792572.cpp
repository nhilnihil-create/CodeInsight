#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> divider = {"dream", "dreamer", "erase", "eraser"};
    reverse(s.begin(), s.end());
    for (auto&& d : divider) reverse(d.begin(), d.end());

    size_t index = 0;
    bool enable = true;

    while (enable) {
        if (index == s.size()) break;
        for (const auto& d : divider) {
            if (s.substr(index, d.size()) == d) {
                index += d.size();
                enable = true;
                break;
            }
            else {
                enable = false;
            }
        }
    }

    cout << (enable ? "YES" : "NO") << endl;
    return EXIT_SUCCESS;
}
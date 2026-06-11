// abc049-c
#include <iostream>
#include <algorithm>
#include <string.h> // strdup
using namespace std;

int main() {
    string s;

    string sa[] = {
        "dream", "dreamer", "erase", "eraser"
    };

    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < 4; i++) {
        reverse(sa[i].begin(), sa[i].end());
    }

    bool valid = true;
    for (size_t pos = 0; valid && pos < s.size(); ) {
        size_t offset = 0;
        for (int i = 0; i < 4; i++) {
            int cmp = strncmp(s.c_str() + pos, sa[i].c_str(), sa[i].length());
            if (cmp == 0) {
                offset = sa[i].length();
                break;
            }
        }
        if (offset != 0) {
            pos += offset;
        } else {
            valid = false;
        }
    }

    string result = valid ? "YES": "NO";
    cout << result << endl;
    return 0;
}

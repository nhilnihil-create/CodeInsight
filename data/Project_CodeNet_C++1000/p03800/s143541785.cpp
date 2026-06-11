#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> vs{"oo", "ox", "xx", "xo"};
    for (auto r : vs) {
        int flag = 1;
        string res(n, ' ');
        res[0] = r[0];
        res[1] = r[1];
        for (int i = 1; i < n - 1; i++) {
            char c = 'o';
            if (res[i] != s[i]) c = 'x';
            if (c == 'o') {
                res[(i + 1) % n] = res[i - 1];
            } else {
                res[(i + 1) % n] = (res[i - 1] == 'o' ? 'x' : 'o');
            }
        }

        if (res[n - 1] == s[n - 1] && res[0] != res[n - 2]) flag = 0;
        if (res[n - 1] != s[n - 1] && res[0] == res[n - 2]) flag = 0;
        if (res[0] == s[0] && res[1] != res.back()) flag = 0;
        if (res[0] != s[0] && res[1] == res.back()) flag = 0;
        if (flag == 1) {
            for (auto rr : res) {
                if (rr == 'o')
                    cout << 'S';
                else
                    cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}

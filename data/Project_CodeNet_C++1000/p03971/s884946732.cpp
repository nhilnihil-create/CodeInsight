#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int kokunai = 0, kaigai = 0;

    for (auto &&i : s) {
        bool passed = false;

        switch (i) {
            case 'a':
                if (kokunai + kaigai < a + b) {
                    kokunai++;
                    passed = true;
                }
                break;

            case 'b':
                if (kokunai + kaigai < a + b && kaigai < b) {
                    kaigai++;
                    passed = true;
                }
                break;

            case 'c':
                break;
        }

        cout << (passed ? "Yes" : "No") << endl;
    }
}

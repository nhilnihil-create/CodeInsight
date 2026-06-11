#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    bool check[10];
    for (int i = 0; i < 10; ++i) {
        check[i] = true;
    }

    for (int i = 0; i < k; ++i) {
        int j;
        cin >> j;
        check[j] = false;
    }
    for (int i = n; ;++i) {
        string s = to_string(i);
        bool c = true;
        for (int j = 0; j < s.length(); ++j) {
            if (check[(int)(s[j]) - '0'] == false) {
                c = false;
            }
        }
        if (c == true) {
            cout << s << endl;
            break;
        }
    }
    return 0;
}

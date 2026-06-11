#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int n = str.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (str[i] == 'p') --res;
        } else {
            if (str[i] == 'g') ++res;
        }
    }
    cout << res << endl;
}

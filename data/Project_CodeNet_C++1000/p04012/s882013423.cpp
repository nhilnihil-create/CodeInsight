#include <bits/stdc++.h>
using namespace std;

int main() {
    string w;
    cin >> w;

    string res = "Yes";
    int cnt;
    for (char c = 'a'; c <= 'z'; c++) {
        cnt = 0;
        for (int i = 0; i < w.size(); i++) {
            if (w.at(i) == c) cnt++;
        }
        if (cnt % 2 == 1) res = "No";
    }

    cout << res << endl;

    return 0;
}
            

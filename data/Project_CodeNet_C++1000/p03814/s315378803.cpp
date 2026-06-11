#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int min = s.size(), max = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'A' && i < min) min = i;
        if (s.at(i) == 'Z' && i > max) max = i;
    }

    cout << max - min +1 << endl;

    return 0;
}

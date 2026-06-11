#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, result = "";
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1')
            result += "1";
        else if (s[i] == '0')
            result = result + "0";
        else if (result.size() >= 1)
            result.pop_back();
    }
    cout << result;
}

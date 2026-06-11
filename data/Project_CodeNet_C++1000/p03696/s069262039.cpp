#include "bits/stdc++.h"

using namespace std;

const char OPEN = '(';
const char CLOSE = ')';

string compress(string s) {
    int pos = 0;
    while ((pos = s.find("()", pos)) != string::npos) {
        s.replace(pos, 2, "");
        pos += 0;
    }
    return s;
}

void Main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<string> operation;
    string s = S;
    while (s.size() > compress(s).size()) {
        s = compress(s);
    }
    s = compress(s);
    while (s != "") {
        if (compress("(" + s).size() < s.size()) {
            operation.push_back("(");
            s = compress("(" + s);
        }
        else {
            operation.push_back(")");
            s = compress(s + ")");
        }
    }

    string ans = S;
    for (int i = 0; i < operation.size(); ++i) {
        if (operation[i] == "(") {
            ans = "(" + ans;
        }
        else {
            ans = ans + ")";
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

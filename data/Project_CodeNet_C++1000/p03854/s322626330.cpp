#include <bits/stdc++.h>
using namespace std;

int daydream(string s) {
    string str = s, check;
    reverse(str.begin(), str.end());

    int cnt = 0;
    while (cnt < s.size()) {
        if (str.at(cnt) == 'm') {
            check += "maerd";
            cnt += 5;
        }
        else if (str.at(cnt) == 'e') {
            check += "esare";
            cnt += 5;
        }
        else if (str.at(cnt) == 'r') {
            if (str.at(cnt + 2) == 'm') {
                check += "remaerd";
                cnt += 7;
            }
            else {
                check += "resare";
                cnt += 6;
            }
        }
    }

    reverse(check.begin(), check.end());
    if (s == check) return true;
    else return false;
}

int main() {
    string S;
    cin >> S;

    if (daydream(S)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
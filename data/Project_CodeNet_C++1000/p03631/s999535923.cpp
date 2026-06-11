#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;
    string s = n;
    string temp = s;
    s.front() = n.back();
    s.back() = temp.front();
    if (n == s) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
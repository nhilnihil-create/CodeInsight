#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S.length() < 4) {
        cout << "No" << endl;
    } else if (S.substr(0, 4) == "YAKI") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

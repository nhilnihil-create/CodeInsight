#include <iostream>
using namespace std;
string a;
bool n, w, s, e;

int main() {
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'N') n = true;
        else if (a[i] == 'W') w = true;
        else if (a[i] == 'S') s = true;
        else e = true;
    }
    if (n == s && w == e) cout << "Yes" << endl;
    else cout << "No" << endl;
}
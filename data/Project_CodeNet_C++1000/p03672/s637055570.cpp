#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    S.pop_back();
    while(S.length() > 0) {
        if (S.length() % 2 != 0) {
            S.pop_back(); continue;
        }
        string a = S.substr(0, S.length() / 2), b = S.substr(S.length() / 2, S.length() / 2);
        if (a == b) {
            cout << S.length() << endl; break;
        }
        else S.pop_back();
    }
}

#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    if (S.length() < 4) {
        cout << "No" << endl;
        return 0;
    }
    if (S.substr(0, 4) == "YAKI") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
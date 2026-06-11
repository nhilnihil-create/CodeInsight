#include <iostream>
#include <string>
using namespace std;

bool check(string &S) {

    if (S.size() >= 5) {
        if (S.substr(S.size()-5, S.size()) == "dream") {
            S = S.substr(0, S.size()-5);
            return true;
        }
        else if (S.substr(S.size()-5, S.size()) == "erase") {
            S = S.substr(0, S.size()-5);
            return true;
        }
    }
    if (S.size() >= 6) {
        if (S.substr(S.size()-6, S.size()) == "eraser") {
            S = S.substr(0, S.size()-6);
            return true;
        }
    }
    if (S.size() >= 7) {
        if (S.substr(S.size()-7, S.size()) == "dreamer") {
            S = S.substr(0, S.size()-7);
            return true;
        }
    }
    return false;
}


int main() {
    string S;
    cin >> S;

    while (S.size() > 0) {
        bool judge = check(S);
        if (!judge) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        if(s[i] == '9') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

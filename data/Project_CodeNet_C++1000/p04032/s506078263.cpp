#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int length = s.length();
    for (int i = 0; i < length - 1; ++i) {
        if (s[i] == s[i + 1]) { 
            cout << i + 1  << " " << i + 2<< endl;
            return 0;
        }
    }
    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 2]) { 
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}

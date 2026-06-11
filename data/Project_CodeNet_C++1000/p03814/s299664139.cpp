#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    size_t m = 0;
    for (size_t i=0; i<s.size(); i++) {
        if (s[i] == 'A') {
            m = i;
            break;
        }
    }
    size_t n = 0;
    for (int i=s.size()-1; i>=0; i--) {
        if (s[i] == 'Z') {
            n = i;
            break;
        }
    }

    cout << (n - m + 1) << endl;
}

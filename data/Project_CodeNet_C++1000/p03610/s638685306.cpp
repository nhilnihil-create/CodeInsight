#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    size_t sz = s.size() / 2;
    string s2(sz, '0');

    if (s.size() % 2 != 0)
        s2 = s2 + '0';

    size_t j = 0;
    for (size_t i=0; i<s.size(); ++i) {
        if ((i + 1) % 2 != 0) {
            s2[j] = s[i];
            ++j;
        }
    }
    cout << s2 << endl;
}

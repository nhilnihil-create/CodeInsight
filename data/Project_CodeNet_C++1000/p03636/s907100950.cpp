#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int l = s.length();
    cout << s[0] << l - 2 << s[l-1] << endl;
}
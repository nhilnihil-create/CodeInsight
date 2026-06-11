#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string res = "";
    for(size_t i = 0; i < s.size(); i += 2) res = res + s[i];
    cout << res << endl;
    return EXIT_SUCCESS;
}
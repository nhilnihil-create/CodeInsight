#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string s1, s2;
    s1 = s.replace(5, 1, " ");
    s2 = s1.replace(13, 1, " ");
    cout << s2 << endl;
}

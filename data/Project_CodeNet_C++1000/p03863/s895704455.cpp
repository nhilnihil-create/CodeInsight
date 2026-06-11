#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    if (s[0] == s.back()) {
        if (s.size() & 1) puts("Second");
        else puts("First");
    }
    else {
        if (s.size() & 1) puts("First");
        else puts("Second");
    }
}
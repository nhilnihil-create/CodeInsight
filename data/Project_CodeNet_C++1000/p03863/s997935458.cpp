#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    if(s.front() == s.back()) {
        int n = s.size() - 3;
        if(n%2) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    } else {
        int n = s.size() - 2;
        if(n%2) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    for(int i=1; i<s.size(); i++) {
        if(s[i-1] == s[i]) {
            cout << i << ' ' << i+1 << endl;
            return 0;
        }
    }

    for(int i=2; i<s.size(); i++) {
        if(s[i-2] == s[i]) {
            cout << i-1 << ' ' << i+1 << endl;
            return 0;
        }
    }

    cout << "-1 -1" << endl;
    return 0;
}

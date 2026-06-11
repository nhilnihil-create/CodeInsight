#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string s2 = "";
    for (size_t i = 0; i < s.size(); i++) {
        s2 += s[s.size()-i-1];
    }
    
    string s3 = "";
    for (int i = 0; i < s.size(); i++) {
        if (s2[i] == 'b') {
            s3 += 'd';
        }
        if (s2[i] == 'd') {
            s3 += 'b';
        }
        if (s2[i] == 'p') {
            s3 += 'q';
        }
        if (s2[i] == 'q') {
            s3 += 'p';
        }
    }
    
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s3[i]) {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    
}
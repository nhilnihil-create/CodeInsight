#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    string s;
    
    cin >> s;
    string t = "";
    string r = s;
    reverse(s.begin(), s.end());
    
    for (int i = 0; i < r.length(); i++) {
        if (r[i] == 'b') t += 'd';
        else if (r[i] == 'd') t += 'b';
        else if (r[i] == 'p') t += 'q';
        else if (r[i] == 'q') t += 'p';
    }
    
    if (t == s) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    string a = s;
    reverse(s.begin(), s.end());
    for(int i = 0; i < len; i++) {
        if(a[i]=='b') {
            a[i]='d';
        } else if(a[i]=='d') {
            a[i]='b';
        } else if(a[i]=='p') {
            a[i]='q';
        } else if(a[i]=='q') {
            a[i]='p';
        }
    }
    if(a == s) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

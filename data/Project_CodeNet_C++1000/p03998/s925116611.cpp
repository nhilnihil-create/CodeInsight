#include <iostream>
#include <string>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

char GetHead(string& s) {
    return s[0];
}
int main(void) {
    string a,b,c;
    cin >> a >> b >> c;
    char target = GetHead(a);
    a.erase(a.begin());
    while(1) {
        if (target == 'a') {
            if (a == "") {
                cout << "A" << endl;
                break;
            }
            target = GetHead(a);
            a.erase(a.begin());
        } else if (target == 'b') {
            if (b == "") {
                cout << "B" << endl;
                break;
            }
            target = GetHead(b);
            b.erase(b.begin());
        } else if (target == 'c') {
            if (c == "") {
                cout << "C" << endl;
                break;
            }
            target = GetHead(c);
            c.erase(c.begin());
        }
    }
    return 0;
}

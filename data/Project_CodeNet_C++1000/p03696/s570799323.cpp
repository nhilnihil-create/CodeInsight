#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;  cin >> n;
    string s;   cin >> s;
    int p = 0, q = 0, a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            a++;
        else {
            if (a <= b) {
                p++;
                b++;
                a++;
            }
            else {
                b++;
            }
        }
    }

    for (int i = 0; i < p; i++)
        cout << "(";
    cout << s;
    for (int i = 0; i < a-b; i++)
        cout << ")";
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    string B;
    string C;
    cin >> A >> B >> C;

    char next = 'a';
    string next_str = A;
    while (true) {
        if (next == 'a') {
            if (A.size() == 0) {
                break;
            }
            next = A.at(0);
            A = A.substr(1);
        }
        else if (next == 'b') {
            if (B.size() == 0) {
                break;
            }
            next = B.at(0);
            B = B.substr(1);
        }
        else {
            if (C.size() == 0) {
                break;
            }
            next = C.at(0);
            C = C.substr(1);
        }
    }

    cout << (char)(next - ('a' - 'A')) << endl;

    return 0;
}
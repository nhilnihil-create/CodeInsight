#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, c;

    cin >> a >> b >> c;

    char t = 'a';
    while (true) {
        if (t == 'a') {
            if (!a.size()) {
                cout << "A";
                break;
            }

            t = a.front();
            a = a.substr(1, a.size() - 1);
        } else if (t == 'b') {
            if (!b.size()) {
                cout << "B";
                break;
            }

            t = b.front();
            b = b.substr(1, b.size() - 1);
        } else if (t == 'c') {
            if (!c.size()) {
                cout << "C";
                break;
            }

            t = c.front();
            c = c.substr(1, c.size() - 1);
        }
    }

    return 0;
}

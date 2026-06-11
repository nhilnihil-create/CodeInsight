#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    string a,b,c;
    cin >> a >> b >> c;
    char x = a.front();
    a = a.substr(1);
    while (true) {
        if (x == 'a') {
            if (a.empty()) {
                cout << 'A' << endl;
                break;
            }
            x = a.front();
            a = a.substr(1);
        } else if (x == 'b') {
            if (b.empty()) {
                cout << 'B' << endl;
                break;
            }
            x = b.front();
            b = b.substr(1);
        } else {
            if (c.empty()) {
                cout << 'C' << endl;
                break;
            }
            x = c.front();
            c = c.substr(1);
        } 
    }
    return 0;
}


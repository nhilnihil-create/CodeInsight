#include <iostream>
using namespace std;
int main() {
    int cnt = 0;
    char c;
    const char *T = "CODEFESTIVAL2016";
    for (int i = 0; i < 16; i++) {
        cin >> c;
        if (c != T[i]) cnt++;
    }
    cout << cnt << endl;
}

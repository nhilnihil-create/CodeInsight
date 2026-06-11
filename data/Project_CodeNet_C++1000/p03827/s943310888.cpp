#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int x = 0, x_max = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I')
            x++;
        else
            x--;
        if (x > x_max) x_max = x;
    }
    cout << x_max << endl;
    return 0;
}
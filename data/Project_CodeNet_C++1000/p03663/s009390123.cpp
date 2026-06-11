#include <iostream>
#include <cmath>
using namespace std;

int i, j, n;
string str;

bool interact(long long ask) {
    cout << "? " << ask << endl;
    char c;
    cin >> c;
    return c == 'Y';
}

int main() {
    long long digit = 1;
    int l = 1, r = 10;
    int number;
    long long last = 0;
    int ans;
    string res;
    bool f = true;
    for (i = 0, last = 10; i < 9; i++, last *= 10) {
        if (!interact(last)) {
            f = false;
            digit = last;
            break;
        }
    }
    if (f) {
        ans = 1;
        for (i = 0; i < 9; i++) {
            if (interact(ans + 1)) {
                break;
            } else {
                ans *= 10;
            }
        }
    } else {
        l = 0;r = 9;
        number = 1;
        last -= 1;
        while (digit > 1) {
            if (r - l > 1) {
                number = (r + l) / 2;
                if(interact(last+number*digit)){
                    r = number;
                } else {
                    l = number;
                }
            } else {
                last += r*digit;
                digit /= 10;
                last -= 9*digit;
                l = -1;r = 9;
            }
        }
        ans = last/10;
    }
    cout << "! " << ans << endl;
}

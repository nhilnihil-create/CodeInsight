#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;

    Int next_player = 0; // 0 -> A, 1 -> B, 2 -> C
    char next_checker = ' ';
    while (1) {
        if (next_player == 0) {
            if (a == "") {
                cout << 'A' << endl;
                break;
            } else {
                next_checker = a[0];
                a.erase(a.begin());
            }
        } else if (next_player == 1) {
            if (b == "") {
                cout << 'B' << endl;
                break;
            } else {
                next_checker = b[0];
                b.erase(b.begin());
            }
        } else if (next_player == 2) {
            if (c == "") {
                cout << 'C' << endl;
                break;
            } else {
                next_checker = c[0];
                c.erase(c.begin());
            }
        }
        if (next_checker == 'a') {
            next_player = 0;
        } else if (next_checker == 'b') {
            next_player = 1;
        } else if (next_checker == 'c') {
            next_player = 2;
        }
        //cout << a << " " << b << " " << c << " " << next_checker << " " << next_player << endl;
    }
}


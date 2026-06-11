#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (l > 0) {
                l = l - 1;
            } else {
                r = r + 1;
            }
        } else if (s[i] == '(') {
            l = l + 1;
        }
    }
    for (int i = 0; i < r; i++) cout << '(';
    cout << s;
    for (int i = 0; i < l; i++) cout << ')';
    cout << endl;
}

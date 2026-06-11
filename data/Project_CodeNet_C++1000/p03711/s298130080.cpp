#include <iostream>
#include <vector>
// #include <algorithm>
// #include <set>
// #include <string>
// #include <cmath>
// #include <map>
// #include <iomanip>

#define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}


int main(int argc, char const *argv[]) {
    int x, y;
    cin >> x >> y;

    bool ans;
    if (x == 2) {
        ans = false;
    } else if (x == 4 || x == 6 || x == 9 || x == 11) {
        if (y == 4 || y == 6 || y == 9 || y == 11) {
            ans = true;
        } else {
            ans = false;
        }
    } else {
        if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) {
            ans = true;
        } else {
            ans = false;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

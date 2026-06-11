#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>
// #include <map>
// #include <set>
// #include <cmath>

using namespace std;
typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    ull x;
    cin >> x;
    ull ans = (x / 11) * 2;
    ull res = x % 11;
    if (res > 0 && res <= 6) {
        ans += 1;
    } else if (res > 0) {
        ans += 2;
    }
    cout << ans << endl;
    return 0;
}

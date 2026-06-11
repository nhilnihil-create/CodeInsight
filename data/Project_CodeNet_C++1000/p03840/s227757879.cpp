#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
#include <array>
#include <iomanip>
#include <cassert>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t answer = 0;

    int64_t a_i;
    cin >> a_i;


    int64_t a_o;
    cin >> a_o;

    int x;
    cin >> x;

    int64_t y_1, y_2;
    cin >> y_1;
    cin >> y_2;


    answer += a_o * 2;

    auto try_this = [=](int sub) {
        int64_t mag = min({a_i, y_1, y_2}) - sub;

        if (mag < 0) {
            return (int64_t)0;
        }

        return 6 * mag + ((a_i - mag) / 2) * 4 + ((y_1 - mag) / 2) * 4 + ((y_2 - mag) / 2) * 4;
    };
    cout << (answer + std::max(try_this(0), try_this(1))) / 2;
}

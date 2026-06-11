#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iomanip>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, x, y;

    cin >> n >> k >> x >> y;

    if (n > k) {
        n -= k;
        cout << k * x + n * y << endl;
    }
    else {
        cout << n * x << endl;
    }
}

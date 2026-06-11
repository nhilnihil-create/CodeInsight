#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int ans = 64;
    while (ans > N)ans /= 2;
    cout << ans << endl;
}